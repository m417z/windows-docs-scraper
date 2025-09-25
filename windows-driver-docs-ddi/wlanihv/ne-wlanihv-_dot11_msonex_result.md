# _DOT11_MSONEX_RESULT enumeration

## Description

**Important** The [Native 802.11 Wireless LAN](https://learn.microsoft.com/previous-versions/windows/hardware/wireless/ff560689(v=vs.85)) interface is deprecated in Windows 10 and later. Please use the WLAN Device Driver Interface (WDI) instead. For more information about WDI, see [WLAN Universal Windows driver model](https://learn.microsoft.com/windows-hardware/drivers/network/wifi-universal-driver-model).

The DOT11_MSONEX_RESULT enumeration defines the results of the 802.1X authentication operation
performed by the operating system through a call to the
[Dot11ExtStartOneX](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlanihv/nc-wlanihv-dot11ext_onex_start) function.

## Constants

### `DOT11_MSONEX_SUCCESS`

The 802.1X authentication operation succeeded.

### `DOT11_MSONEX_FAILURE`

The 802.1X authentication operation failed.

### `DOT11_MSONEX_IN_PROGRESS`

The 802.1X authentication operation is in progress.

## Syntax

```cpp
typedef enum _DOT11_MSONEX_RESULT {
  DOT11_MSONEX_SUCCESS      = 0,
  DOT11_MSONEX_FAILURE      = 1,
  DOT11_MSONEX_IN_PROGRESS  = 2
} DOT11_MSONEX_RESULT, *PDOT11_MSONEX_RESULT;
```

## Remarks

After the IHV Extensions DLL initiates an 802.1X authentication operation, the operating system calls
the
[Dot11ExtIhvOneXIndicateResult](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlanihv/nc-wlanihv-dot11extihv_onex_indicate_result) IHV handler function to complete the operation. When it calls this
function, the operating system passes a DOT11_MSONEX_RESULT value to the
*OneXResult* parameter to specify the result of the authentication operation.

## See also

[Dot11ExtIhvOneXIndicateResult](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlanihv/nc-wlanihv-dot11extihv_onex_indicate_result)

[Dot11ExtStartOneX](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlanihv/nc-wlanihv-dot11ext_onex_start)