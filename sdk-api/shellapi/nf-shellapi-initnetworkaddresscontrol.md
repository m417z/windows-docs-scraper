# InitNetworkAddressControl function

## Description

Initializes the network address control window class.

## Return value

Type: **BOOL**

**TRUE** if the initialization succeeded; or **FALSE** otherwise.

## Remarks

The network address control looks like an edit control and offers the additional functionality of network address verification. The control uses a balloon tip to display error messages.

This function initializes class WC_NETADDRESS. If this function returns **TRUE**, the control can be created.