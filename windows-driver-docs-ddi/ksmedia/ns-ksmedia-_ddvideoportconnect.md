## Description

The **DDVIDEOPORTCONNECT** structure describes a hardware video port connection.

## Members

### `dwSize`

Specifies the size in bytes of the **DDVIDEOPORTCONNECT** structure.

### `dwPortWidth`

Specifies the width of the hardware video port. This value represents the number of physical pins on the hardware video port. This member must always be filled in, even when the **guidTypeID** assumes a certain size.

### `guidTypeID`

Specifies a GUID that describes the synchronization characteristics of the hardware video port. The following port types are predefined:

| Port Type | Description |
|---|---|
| DDVPTYPE_E_HREFH_VREFH | External syncs where HREF is active high and VREF is active high. |
| DDVPTYPE_E_HREFH_VREFL | External syncs where HREF is active high and VREF is active low. |
| DDVPTYPE_E_HREFL_VREFH | External syncs where HREF is active low and VREF is active high. |
| DDVPTYPE_E_HREFL_VREFL | External syncs where HREF is active low and VREF is active low. |
| DDVPTYPE_BROOKTREE | Sync information is embedded in the data stream using the Brooktree definition. |
| DDVPTYPE_CCIR656 | Sync information is embedded in the data stream according to the CCIR656 specification. |
| DDVPTYPE_PHILIPS | Sync information is embedded in the data stream using the Philips definition. |

### `dwFlags`

Specifies a set of flags that identify the capabilities of the hardware video port connection. This member can be a bitwise OR of any of the following flags:

| Flag | Meaning |
|---|---|
| DDVPCONNECT_DISCARDSVREFDATA | The device discards any data written during the VREF period, causing this data to not be written to the frame buffer. This flag should be set only by the driver. |
| DDVPCONNECT_DOUBLECLOCK | When set by the driver, this flag indicates that the hardware video port is capable of double clocking the data. When set by the client, it indicates that the hardware video port should double clock the data. This flag is valid only in a hardware video port with a **guidTypeID** that supports an external sync. |
| DDVPCONNECT_HALFLINE | When set by the driver, this flag indicates that the hardware video port supports writing half lines into the frame buffer, sometimes causing the data to not be displayed correctly. When set by the client, it indicates that the driver may write half lines. |
| DDVPCONNECT_INTERLACED | When set by the driver, this flag indicates that the hardware video port supports interlaced signals. When set by the client, it indicates that the signal is interlaced. |
| DDVPCONNECT_INVERTPOLARITY | When set by the driver, this flag indicates that the hardware video port is capable of inverting the field polarities; that is, treating even fields as odd and vice versa. When set by the client, it indicates that the hardware video port should invert the field polarities. |
| DDVPCONNECT_SHAREEVEN | This is currently an unimplemented feature and should be ignored by the driver. |
| DDVPCONNECT_SHAREODD | This is currently an unimplemented feature and should be ignored by the driver. |
| DDVPCONNECT_VACT | When set by the driver, this flag indicates that the hardware video port is capable of using an external VACT signal. When set by the client, it indicates that the hardware video port should use the external VACT signal. |

### `dwReserved1`

Reserved for system use and should be set to zero.

## Remarks

The driver's [DdVideoPortGetConnectInfo](https://learn.microsoft.com/windows/win32/api/ddrawint/nc-ddrawint-pdd_vportcb_getvportconnect) callback routine initializes a DDVIDEOPORTCONNECT structure for every connection that the hardware video port supports. The client can change the **dwFlags** member of one of the driver's **DDVIDEOPORTCONNECT** structures before calling the driver's [DdVideoPortCanCreate](https://learn.microsoft.com/windows/win32/api/ddrawint/nc-ddrawint-pdd_vportcb_cancreatevideoport) callback.

## See also

[DdVideoPortCanCreate](https://learn.microsoft.com/windows/win32/api/ddrawint/nc-ddrawint-pdd_vportcb_cancreatevideoport)

[DdVideoPortGetConnectInfo](https://learn.microsoft.com/windows/win32/api/ddrawint/nc-ddrawint-pdd_vportcb_getvportconnect)