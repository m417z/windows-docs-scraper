# IBackgroundCopyFile3::GetValidationState

## Description

Gets the current validation state of this file.

## Parameters

### `pState` [out]

**TRUE** if the contents of the file is valid, otherwise, **FALSE**.

## Return value

The method returns the following return values.

| Return code | Description |
| --- | --- |
| **S_OK** | Success |

## Remarks

Note that **FALSE** may not mean that the file is not valid, it may mean the [IBackgroundCopyFile3::SetValidationState](https://learn.microsoft.com/windows/desktop/api/bits3_0/nf-bits3_0-ibackgroundcopyfile3-setvalidationstate) has not been called.

## See also

[IBackgroundCopyFile3](https://learn.microsoft.com/windows/desktop/api/bits3_0/nn-bits3_0-ibackgroundcopyfile3)

[IBackgroundCopyFile3::SetValidationState](https://learn.microsoft.com/windows/desktop/api/bits3_0/nf-bits3_0-ibackgroundcopyfile3-setvalidationstate)

[IBitsPeerCacheRecord::IsFileValidated](https://learn.microsoft.com/windows/desktop/api/bits3_0/nf-bits3_0-ibitspeercacherecord-isfilevalidated)