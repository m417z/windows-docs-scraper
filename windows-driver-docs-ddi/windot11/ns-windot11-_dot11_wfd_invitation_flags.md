# _DOT11_WFD_INVITATION_FLAGS structure

## Description

> [!Important]
> [WiFiCx](https://learn.microsoft.com/windows-hardware/drivers/netcx/wifi-wdf-class-extension-wificx) is the new Wi-Fi driver model released in Windows 11. We recommend that you use WiFiCx to take advantage of the latest features. The WDI driver model is now in maintenance mode and will only receive high priority fixes.

The **DOT11_WFD_INVITATION_FLAGS** structure represents the Invitation Attributes used during the Invitation procedure.

## Members

### `InvitationType`

The type of group invitation. The invitation types have the following meanings.

| Value | Meaning |
| --- | --- |
| **Join**<br><br>0 | An invitation to join an active group. |
| **Reinvoke**<br><br>1 | The invitation is reinvoked. |

### `Reserved`

Reserved.

## Syntax

```cpp
typedef struct _DOT11_WFD_INVITATION_FLAGS {
  UCHAR InvitationType:1;
  UCHAR Reserved:7;
} DOT11_WFD_INVITATION_FLAGS, *PDOT11_WFD_INVITATION_FLAGS;
```