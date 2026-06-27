import numpy as np
import cv2

image = cv2.imread("test_2 example task №11.jpg")
cv2.imshow("original image", image)
cv2.waitKey(0)

blurred_image = cv2.GaussianBlur(image, (11, 11), 0)
cv2.imshow("clean image", blurred_image)
cv2.waitKey(0)

hsv_image = cv2.cvtColor(blurred_image, cv2.COLOR_BGR2HSV)
cv2.imshow("hsv image", hsv_image)
cv2.waitKey(0)

hsv_green_min = np.array((36, 25, 25), np.uint8)
hsv_green_max = np.array((70, 255, 255), np.uint8)
green_mask = cv2.inRange(hsv_image, hsv_green_min, hsv_green_max)
cv2.imshow("green mask", green_mask)
cv2.waitKey(0)

green_contours, green_hierarchy = cv2.findContours(green_mask.copy(), cv2.RETR_TREE, cv2.CHAIN_APPROX_SIMPLE)

