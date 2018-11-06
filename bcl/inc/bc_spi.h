#ifndef _BC_SPI_H
#define _BC_SPI_H

#include <bc_common.h>

//! @addtogroup bc_spi bc_spi
//! @brief Driver for SPI bus
//! @{

//! @brief SPI communication speed

typedef enum
{
    //! @brief SPI communication speed is 125 kHz
    BC_SPI_SPEED_125_KHZ = 0,

    //! @brief SPI communication speed is 250 kHz
    BC_SPI_SPEED_250_KHZ = 1,

    //! @brief SPI communication speed is 500 kHz
    BC_SPI_SPEED_500_KHZ = 2,

    //! @brief SPI communication speed is 1 MHz
    BC_SPI_SPEED_1_MHZ = 3,

    //! @brief SPI communication speed is 2 MHz
    BC_SPI_SPEED_2_MHZ = 4,

    //! @brief SPI communication speed is 4 MHz
    BC_SPI_SPEED_4_MHZ = 5,

    //! @brief SPI communication speed is 8 MHz
    BC_SPI_SPEED_8_MHZ = 6,

    //! @brief SPI communication speed is 16 MHz
    BC_SPI_SPEED_16_MHZ = 7

} bc_spi_speed_t;

//! @brief SPI mode of operation

typedef enum
{
    //! @brief SPI mode of operation is 0 (CPOL = 0, CPHA = 0)
    BC_SPI_MODE_0 = 0,

    //! @brief SPI mode of operation is 1 (CPOL = 0, CPHA = 1)
    BC_SPI_MODE_1 = 1,

    //! @brief SPI mode of operation is 2 (CPOL = 1, CPHA = 0)
    BC_SPI_MODE_2 = 2,

    //! @brief SPI mode of operation is 3 (CPOL = 1, CPHA = 1)
    BC_SPI_MODE_3 = 3

} bc_spi_mode_t;

//! @brief SPI event

typedef enum
{
    //! @brief SPI event is completed
    BC_SPI_EVENT_DONE = 1

} bc_spi_event_t;

//! @brief Initialize SPI channel
//! @param[in] speed SPI communication speed
//! @param[in] mode SPI mode of operation

void bc_spi_init(bc_spi_speed_t speed, bc_spi_mode_t mode);

//! @brief Set SPI communication speed
//! @param[in] speed SPI communication speed

void bc_spi_set_speed(bc_spi_speed_t speed);

//! @brief Set SPI timing
//! @param[in] cs_delay in us
//! @param[in] delay in us
//! @param[in] cs_quit in us

void bc_spi_set_timing(uint16_t cs_delay, uint16_t delay, uint16_t cs_quit);

//! @brief Get SPI communication speed
//! @return SPI communication speed

bc_spi_speed_t bc_spi_get_speed(void);

//! @brief Set SPI mode of operation
//! @param[in] mode SPI mode of operation

void bc_spi_set_mode(bc_spi_mode_t mode);

//! @brief Get SPI mode of operation
//! @return SPI mode of operation

bc_spi_mode_t bc_spi_get_mode(void);

//! @brief Check if is ready for transfer
//! @return true If ready
//! @return false If not ready

bool bc_spi_is_ready(void);

//! @brief Execute SPI transfer
//! @param[in] source Pointer to source buffer
//! @param[out] destination Pointer to destination buffer
//! @param[in] length Number of bytes to be transferred

bool bc_spi_transfer(const void *source, void *destination, size_t length);

//! @brief Execute async SPI transfer
//! @param[in] source Pointer to source buffer
//! @param[out] destination Pointer to destination buffer
//! @param[in] length Number of bytes to be transferred
//! @param[in] event_handler Function address (can be NULL)
//! @param[in] event_param Optional event parameter (can be NULL)

bool bc_spi_async_transfer(const void *source, void *destination, size_t length, void (*event_handler)(bc_spi_event_t event, void *event_param), void (*event_param));

//! @brief Execute single byte SPI transfer
//! @param[in] transmit byte
//! @return received byte

uint8_t bc_spi_transfer_byte(uint8_t value);

//! @}

#endif // _BC_SPI_H
