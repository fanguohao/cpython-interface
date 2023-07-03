import cv2



def color2gray(image1, image2):
    global gray_image1, gray_image2
    # Process the input images (e.g., convert to grayscale)
    gray_image1 = cv2.cvtColor(image1, cv2.COLOR_BGR2GRAY)
    gray_image2 = cv2.cvtColor(image2, cv2.COLOR_BGR2GRAY)

    cv2.imshow("python", gray_image1)
    cv2.waitKey(0)

    # Apply some additional processing
    # ...

    # Return the processed images
    return gray_image1, gray_image2



