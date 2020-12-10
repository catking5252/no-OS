/***************************************************************************//**
*   @file   iio_ad7124.h
*   @brief  Header file of iio_ad7124
*   @author Andrei Drimbarean (andrei.drimbarean@analog.com)
********************************************************************************
* Copyright 2020(c) Analog Devices, Inc.
*
* All rights reserved.
*
* Redistribution and use in source and binary forms, with or without
* modification, are permitted provided that the following conditions are met:
*  - Redistributions of source code must retain the above copyright
*    notice, this list of conditions and the following disclaimer.
*  - Redistributions in binary form must reproduce the above copyright
*    notice, this list of conditions and the following disclaimer in
*    the documentation and/or other materials provided with the
*    distribution.
*  - Neither the name of Analog Devices, Inc. nor the names of its
*    contributors may be used to endorse or promote products derived
*    from this software without specific prior written permission.
*  - The use of this software may or may not infringe the patent rights
*    of one or more patent holders.  This license does not release you
*    from the requirement that you obtain separate licenses from these
*    patent holders to use this software.
*  - Use of the software either in source or binary form, must be run
*    on or directly connected to an Analog Devices Inc. component.
*
* THIS SOFTWARE IS PROVIDED BY ANALOG DEVICES "AS IS" AND ANY EXPRESS OR
* IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, NON-INFRINGEMENT,
* MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
* IN NO EVENT SHALL ANALOG DEVICES BE LIABLE FOR ANY DIRECT, INDIRECT,
* INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
* LIMITED TO, INTELLECTUAL PROPERTY RIGHTS, PROCUREMENT OF SUBSTITUTE GOODS OR
* SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
* CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
* OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
* OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*******************************************************************************/

#ifndef IIO_AD7124_H
#define IIO_AD7124_H

/******************************************************************************/
/***************************** Include Files **********************************/
/******************************************************************************/

#include "iio.h"
#include "ad7124.h"

/******************************************************************************/
/*************************** Types Declarations *******************************/
/******************************************************************************/

/**
 * @struct iio_ad7124_desc
 * @brief AD7124 IIO driver handler structure.
 */
struct iio_ad7124_desc {
	/** Generic IIO device handler */
	struct iio_device *iio_ad7124_device;
	/** Device driver handler */
	struct ad7124_dev *ad7124_driver_handler;
	/** Pointer to the RAM block reserved for data streaming */
	uint8_t *ddr_base_addr;
};

/**
 * @struct iio_ad7124_init_param
 * @brief AD7124 IIO driver initialization structure.
 */
struct iio_ad7124_init_param {
	/** Device driver initailization structure */
	struct ad7124_dev *ad7124_driver_handler;
	/** Pointer to the RAM block reserved for data streaming */
	uint8_t *ddr_base_addr;
};

/******************************************************************************/
/************************ Functions Declarations ******************************/
/******************************************************************************/

/** Initialize the AD7124 IIO driver. */
int32_t iio_ad7124_init(struct iio_ad7124_desc **desc,
			struct iio_ad7124_init_param *init_param);
/** Free memory allocated by iio_ad7124_init(). */
int32_t iio_ad7124_remove(struct iio_ad7124_desc *desc);

#endif /** IIO_AD7124_H */
