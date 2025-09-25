# ITfConfigureSystemKeystrokeFeed::DisableSystemKeystrokeFeed

## Description

Prevents the TSF manager from processing keystrokes.

## Return value

This method can return one of these values.

| Value | Description |
| --- | --- |
| **S_OK** | The method was successful. |

## Remarks

By default, the TSF manager will process keystrokes and pass them to the text services. An application prevents this by calling this method. Typically, this method is called when text service input is inappropriate, for example when a menu is displayed.

Calls to this method are cumulative, so every call to this method requires a subsequent call to [ITfConfigureSystemKeystrokeFeed::EnableSystemKeystrokeFeed](https://learn.microsoft.com/windows/desktop/api/msctf/nf-msctf-itfconfiguresystemkeystrokefeed-enablesystemkeystrokefeed).

## See also

[ITfConfigureSystemKeystrokeFeed interface](https://learn.microsoft.com/windows/win32/api/msctf/nn-msctf-itfconfiguresystemkeystrokefeed), [ITfConfigureSystemKeystrokeFeed::EnableSystemKeystrokeFeed](https://learn.microsoft.com/windows/win32/api/msctf/nf-msctf-itfconfiguresystemkeystrokefeed-enablesystemkeystrokefeed)