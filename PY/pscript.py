import cv2


def color2gray(image1, image2):
    global gray_image1, gray_image2
    gray_image1 = cv2.cvtColor(image1, cv2.COLOR_BGR2GRAY)
    gray_image2 = cv2.cvtColor(image2, cv2.COLOR_BGR2GRAY)

    return gray_image1, gray_image2, gray_image1
