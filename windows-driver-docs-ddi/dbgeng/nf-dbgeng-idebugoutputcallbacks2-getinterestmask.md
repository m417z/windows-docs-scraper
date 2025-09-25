# IDebugOutputCallbacks2::GetInterestMask

## Description

Allows the callback object to describe which kinds of output notifications it wants to receive.

## Parameters

### `Mask`

The type of output notification to receive.

| Value | Meaning |
| --- | --- |
| **DEBUG_OUTCBI_EXPLICIT_FLUSH**<br><br>0x00000001 | Indicates that the callback wants notifications of all explicit flushes. |
| **DEBUG_OUTCBI_TEXT**<br><br>0x00000002 | Indicates that the callback wants content in text form. |
| **DEBUG_OUTCBI_DML**<br><br>0x00000004 | Indicates that the callback wants content in markup form. |
| **DEBUG_OUTCBI_ANY_FORMAT**<br><br>0x00000006 | Indicates that the callback wants content in any format. |

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IDebugOutputCallbacks2](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugoutputcallbacks2)