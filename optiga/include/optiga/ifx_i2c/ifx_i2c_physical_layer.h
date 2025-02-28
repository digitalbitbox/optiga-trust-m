/**
* \copyright
* MIT License
*
* Copyright (c) 2021 Infineon Technologies AG
*
* Permission is hereby granted, free of charge, to any person obtaining a copy
* of this software and associated documentation files (the "Software"), to deal
* in the Software without restriction, including without limitation the rights
* to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
* copies of the Software, and to permit persons to whom the Software is
* furnished to do so, subject to the following conditions:
*
* The above copyright notice and this permission notice shall be included in all
* copies or substantial portions of the Software.
*
* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
* IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
* FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
* AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
* LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
* OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
* SOFTWARE
*
* \endcopyright
*
* \author Infineon Technologies AG
*
* \file ifx_i2c_physical_layer.h
*
* \brief   This file defines the API prototype for physical layer of the Infineon I2C Protocol Stack library.
*
* \ingroup  grIFXI2C
*
* @{
*/

#ifndef _IFX_I2C_PHYSICAL_LAYER_H_
#define _IFX_I2C_PHYSICAL_LAYER_H_

#ifdef __cplusplus
extern "C" {
#endif

#include "ifx_i2c_config.h"

/**
 * \brief Function for initializing the module.
 *
 * \details
 * Function initializes and enables the module
 * - It registers an event handler to receive events from this module.
 *
 * \pre
 * - This function must be called before using the module.
 *
 * \note
 * - None
 *
 * \param[in,out] p_ctx                   Pointer to IFX I2C context.
 * \param[in]     handler                 Function pointer to the event handler of the upper layer.
 *
 * \retval        IFX_I2C_STACK_SUCCESS   If initialization was successful.
 * \retval        IFX_I2C_STACK_ERROR     If the module is already initialized.
 */
optiga_lib_status_t ifx_i2c_pl_init(ifx_i2c_context_t * p_ctx,
                                    ifx_i2c_event_handler_t handler);

/**
 * \brief Function for sending a frame.
 *
 * \details
 * Asynchronous function to send a frame.
 * - The function returns immediately.
 * - One of the following events is propagated to the event handler registered with #ifx_i2c_pl_init
 *
 * \pre
 * - None
 *
 * \note
 * - None
 *
 * \param[in,out]  p_ctx                     Pointer to IFX I2C context.
 * \param[in]      p_frame                   Buffer containing the frame.
 * \param[in]      frame_len                 Frame length.
 *
 * \retval         IFX_I2C_STACK_SUCCESS     If function was successful.
 * \retval         IFX_I2C_STACK_ERROR       If the module is busy.
 */
optiga_lib_status_t ifx_i2c_pl_send_frame(ifx_i2c_context_t * p_ctx,
                                          uint8_t * p_frame,
                                          uint16_t frame_len);

/**
 * \brief Function for receiving a frame.
 *
 * \details
 * Asynchronous function to receive a frame
 * - The function returns immediately.
 * - One of the following events is propagated to the event handler registered with #ifx_i2c_pl_init
 *
 * \pre
 * - None
 *
 * \note
 * - None
 *
 * \param[in] p_ctx                   Pointer to IFX I2C context.
 *
 * \retval    IFX_I2C_STACK_SUCCESS   If function was successful.
 * \retval    IFX_I2C_STACK_ERROR     If the module is busy.
 */
optiga_lib_status_t ifx_i2c_pl_receive_frame(ifx_i2c_context_t * p_ctx);


/**
 * \brief Function for setting slave address.
 *
 * \details
 * Synchronous function to set slave address.
 *
 * \pre
 * - None
 *
 * \note
 * - None
 *
 * \param[in]    p_ctx                   Pointer to IFX I2C context.
 * \param[in]    slave_address           Holds new slave address[7 Bit] to be set.
 * \param[in]    storage_type            0: To set the Slave address until next reset.<br>
 *                                       Non-zero: To set the slave address to persistent memory.
 *
 * \retval       IFX_I2C_STACK_SUCCESS   If function was successful.
 * \retval       IFX_I2C_STACK_ERROR     If setting slave address fails.
 */
optiga_lib_status_t ifx_i2c_pl_write_slave_address(ifx_i2c_context_t * p_ctx,
                                                   uint8_t slave_address,
                                                   uint8_t storage_type);
/**
 * @}
 **/

#ifdef __cplusplus
}
#endif
#endif /* _IFX_I2C_PHYSICAL_LAYER_H_ */
