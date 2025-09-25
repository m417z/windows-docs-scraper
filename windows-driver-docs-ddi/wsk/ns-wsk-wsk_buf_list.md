## Description

The **WSK_BUF_LIST** structure is used to send multiple datagrams via a single call to [**WskSendMessages**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/nc-wsk-pfn_wsk_send_messages).

## Members

### `Next`

A pointer to a **WSK_BUF_LIST** structure containing the next data buffer in the list.

### `Buffer`

An initialized [**WSK_BUF**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/ns-wsk-_wsk_buf) structure that describes a data buffer.

## Remarks

## See also

[**WskSendMessages**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/nc-wsk-pfn_wsk_send_messages)

[**WSK_BUF**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/ns-wsk-_wsk_buf)