# ITfConfigureSystemKeystrokeFeed::EnableSystemKeystrokeFeed

## Description

Enables the TSF manager to process keystrokes after being disabled by DisableSystemKeystrokeFeed.

## Return value

This method can return one of these values.

| Value | Description |
| --- | --- |
| **S_OK** | The method was successful. |
| **E_UNEXPECTED** | There was no corresponding call to DisableSystemKeystrokeFeed. |

## Remarks

By default, the TSF manager will process keystrokes and pass them to the text services. An application prevents this by calling **DisableSystemKeystrokeFeed** .

Calls to **DisableSystemKeystrokeFeed** are cumulative, so every call to **DisableSystemKeystrokeFeed** requires a subsequent call to **EnableSystemKeystrokeFeed**. Calling **EnableSystemKeystrokeFeed** will not enable keystroke processing if **DisableSystemKeystrokeFeed** is called more than once.

## See also

[ITfConfigureSystemKeystrokeFeed interface](https://learn.microsoft.com/windows/win32/api/msctf/nn-msctf-itfconfiguresystemkeystrokefeed), [ITfConfigureSystemKeystrokeFeed::DisableSystemKeystrokeFeed](https://learn.microsoft.com/windows/win32/api/msctf/nf-msctf-itfconfiguresystemkeystrokefeed-disablesystemkeystrokefeed)