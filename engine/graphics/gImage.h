/*
 * Copyright (C) 2016 Nitra Games Ltd.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef ENGINE_GRAPHICS_GIMAGE_H_
#define ENGINE_GRAPHICS_GIMAGE_H_

#include "gTexture.h"


class gImage : public gTexture {
public:
	gImage();
	virtual ~gImage();

	/**
	 * Loads an image from the given fullpath.
	 *
	 * Supported image formats can be found in the class description.
	 *
	 * The image might be stored anywhere on the hard disk or other storage
	 * devices out of the project folder.
	 *
	 * This function was created primarily for development purposes. Due to the
	 * difficulties and errors of storing images in a messy fashion, developers
	 * are encouraged to use the loadImage function instead.
	 *
	 * @param fullPath The full path to the image file. It should contain the
	 * full path of the folder where the image is located, the name of the image
	 * and its extension. It is case sensitive.
	 *
	 * @return Image id number generated by OpenGL.
	 */
	unsigned int load(std::string fullPath);

	/**
	 * Loads an image from the project's images folder.
	 *
	 * Supported image formats can be found in the class description.
	 *
	 * There is no need to enter the folder address, as the function loads from
	 * the project's own images folders. It is only necessary to specify the name
	 * and extension of the image. For example, giving an address such as "image.jpg"
	 * is sufficient. Make sure that the named image is placed in the project's
	 * images folder.
	 *
	 * Project's default images folder is ProjectLocation/assets/images directory.
	 *
	 * The project's image folder may vary depending on the project's scaling
	 * settings. In case of SCALING_NONE and SCALING_AUTO, this function loads images
	 * from ProjectLocation/assets/images folder. In case of SCALING_MIPMAP,
	 * ProjectLocation/assets/mipmaps/DeviceResolution folder becomes images folder.
	 *
	 * Developers are encouraged to use this function for image loading so that an
	 * efficient and shareable work can be carried out.
	 *
	 * @param imagePath The fullname of the image stored under project's images
	 * folder. Fullname should contain image name and its extension. It is case
	 * sensitive.
	 *
	 * @return Image id number generated by OpenGL.
	 */
	unsigned int loadImage(std::string imagePath);

	void loadData(std::string fullPath);
	void loadImageData(std::string imagePath);
	unsigned int useData();

    void setImageData(unsigned char* imageData);
    unsigned char* getImageData();

    void setImageDataHDR(float* imageData);
    float* getImageDataHDR();

    void clearData();
};

#endif /* ENGINE_GRAPHICS_GIMAGE_H_ */
