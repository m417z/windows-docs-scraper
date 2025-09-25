# IATSCComponentType::put_Flags

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

The **put_Flags** method specifies whether an audio component is in AC-3 format.

## Parameters

### `flags` [in]

Specifies one of the following values:

| Value | Description |
| --- | --- |
| Zero | The component does not contain AC-3 audio |
| ATSCCT_AC3 | The component contains AC-3 audio |

See [ATSCComponentTypeFlags Enumeration](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/atsccomponenttypeflags).

## Return value

Returns S_OK if successful. If the method fails, error information can be retrieved using the standard COM **IErrorInfo** interface.

## See also

[IATSCComponentType Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/tuner/nn-tuner-iatsccomponenttype)