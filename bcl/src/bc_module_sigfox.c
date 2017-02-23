#include <bc_module_sigfox.h>

void bc_module_sigfox_init(bc_module_sigfox_t *self)
{
    bc_wssfm10r1at_init(self, BC_GPIO_P6, BC_UART_UART1);
}

void bc_module_sigfox_set_event_handler(bc_module_sigfox_t *self, void (*event_handler)(bc_module_sigfox_t *, bc_module_sigfox_event_t, void *), void *event_param)
{
    bc_wssfm10r1at_set_event_handler(self, (void (*)(bc_wssfm10r1at_t *, bc_wssfm10r1at_event_t, void *)) event_handler, event_param);
}

bool bc_module_sigfox_is_ready(bc_module_sigfox_t *self)
{
    return bc_wssfm10r1at_is_ready(self);
}

bool bc_module_sigfox_send_rf_frame(bc_module_sigfox_t *self, const void *buffer, size_t length)
{
    return bc_wssfm10r1at_send_rf_frame(self, buffer, length);
}
