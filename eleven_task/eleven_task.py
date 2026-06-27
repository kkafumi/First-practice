import numpy as np
import cv2
#чтение изображения
image = cv2.imread("/home/kkafumi/projects/First-practice/eleven_task/test_11.jpg")
cv2.imshow("original image", image) # показ изображения
cv2.waitKey(0) # ждём нажатия кнопки (0 - бесконечно)

blurred_image = cv2.GaussianBlur(image, (11, 11), 0) # размытие для снижения шумов
cv2.imshow("blurred image", blurred_image)
cv2.waitKey(0)

hsv_image = cv2.cvtColor(blurred_image, cv2.COLOR_BGR2HSV) # перевод в HSV
cv2.imshow("hsv image", hsv_image)
cv2.waitKey(0)

# определяем границы поиска
hsv_green_min = np.array((36, 25, 25), np.uint8)
hsv_green_max = np.array((70, 255, 255), np.uint8)
green_mask = cv2.inRange(hsv_image, hsv_green_min, hsv_green_max) # создаём маску (зелёные объекты - белыею. остальное - чёрное)
cv2.imshow("green mask", green_mask)
cv2.waitKey(0)

green_contours, green_hierarchy = cv2.findContours(green_mask.copy(), cv2.RETR_TREE, cv2.CHAIN_APPROX_SIMPLE) # ищем только зелёные объекты и их иерархию

for i, contour in enumerate(green_contours):
    if(green_hierarchy[0][i][3] == -1): # только если внешний контур (Parent == -1)
        x, y, w, h = cv2.boundingRect(contour) #левый верхний - правый нижний углы минимального прямоугольника, описывающего фигуру
        center = (int(x + w/2), int(y + h/2))
        print(x,y,w,h)
        
        cv2.circle(image, center, 9, (0, 0, 255), -1) # отмечаем центр на изображении (-1 закрашивает круг)
        cv2.drawContours(image, [contour], -1, (255, 0, 0), 5) # обводим контур
cv2.imshow("green figures", image)
cv2.waitKey(0)

# повторяем то же самое, но для жёлтых объектов
hsv_yellow_min = np.array((20, 25, 25), np.uint8)
hsv_yellow_max = np.array((36, 255, 255), np.uint8)
yellow_mask = cv2.inRange(hsv_image, hsv_yellow_min, hsv_yellow_max)
cv2.imshow("yellow mask", yellow_mask)
cv2.waitKey(0)

yellow_contours, yellow_hierarchy = cv2.findContours(yellow_mask.copy(), cv2.RETR_TREE, cv2.CHAIN_APPROX_SIMPLE)

for i, contour in enumerate(yellow_contours):
    if(yellow_hierarchy[0][i][3] == -1):
        x, y, w, h = cv2.boundingRect(contour)
        center = (int(x + w/2), int(y + h/2))
        print(x,y,w,h)
        
        cv2.circle(image, center, 9, (0, 0, 255), -1)
        cv2.drawContours(image, [contour], -1, (0, 255, 0), 5)

cv2.imshow("green and yellow figures", image)
cv2.waitKey(0)

cv2.destroyAllWindows() # закрываем все окна, открытые с помощью imshow