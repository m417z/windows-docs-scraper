# IDiscFormat2Data::get_LastWrittenAddressOfPreviousSession

## Description

Retrieves the last sector of the previous write session.

## Parameters

### `value` [out]

 Address where the previous write operation ended.

The value is -1 if the media is blank or does not support multi-session writing (indicates that no previous session could be detected).

## Return value

S_OK is returned on success, but other success codes may be returned as a result of implementation. The following error codes are commonly returned on operation failure, but do not represent the only possible error values:

| Return code | Description |
| --- | --- |
| **E_NOTIMPL** | Not implemented.<br><br>Value: 0x80004001 |

## Remarks

**Note** This property should not be used. Instead, you should use an interface derived from [IMultisession](https://learn.microsoft.com/windows/desktop/api/imapi2/nn-imapi2-imultisession), such as [IMultisessionSequential](https://learn.microsoft.com/windows/desktop/api/imapi2/nn-imapi2-imultisessionsequential), for importing file data from the previous session.

## See also

[IDiscFormat2Data](https://learn.microsoft.com/windows/desktop/api/imapi2/nn-imapi2-idiscformat2data)

[IDiscFormat2Data::get_NextWritableAddress](https://learn.microsoft.com/windows/desktop/api/imapi2/nf-imapi2-idiscformat2data-get_nextwritableaddress)

[IDiscFormat2Data::get_StartAddressOfPreviousSession](https://learn.microsoft.com/windows/desktop/api/imapi2/nf-imapi2-idiscformat2data-get_startaddressofprevioussession)