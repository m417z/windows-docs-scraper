# IEnumCERTVIEWROW::GetMaxIndex

## Description

The **GetMaxIndex** method retrieves the maximum valid index value after all the rows in the row-enumeration sequence have been referenced.

## Parameters

### `pIndex` [out]

A pointer to a **LONG** variable that contains the maximum index value for the row-enumeration sequence. This method fails if *pIndex* is **NULL**.

## Return value

### C++

If the method succeeds, the method returns S_OK and *pIndex* is set to the maximum index value for the row-enumeration sequence.

If traversal to the last row has not occurred, this method fails with a return value of E_UNEXPECTED.

If the method fails, it returns an **HRESULT** value that indicates the error. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).

### VB

The return value is the maximum index value for the row-enumeration sequence. This method fails if traversal to the last row has not occurred.

## Remarks

Successful completion of this method is dependent on reaching the last row of the enumeration sequence. The maximum row index can be useful to size a scroll bar or display window, but it can also be resource-intensive to compute because it requires evaluating the entire query. For some queries, column data for each row must be examined to determine whether it is included in the view. After the user has paged through all of the data or explicitly requested to proceed to the end, the maximum row index is preserved.

To navigate through the row-enumeration sequence, call the following methods.

| Method | Description |
| --- | --- |
| [IEnumCERTVIEWROW::Reset](https://learn.microsoft.com/windows/desktop/api/certview/nf-certview-ienumcertviewrow-reset) | Moves to the beginning of the enumeration sequence. |
| [IEnumCERTVIEWROW::Next](https://learn.microsoft.com/windows/desktop/api/certview/nf-certview-ienumcertviewrow-next) | Moves to the next row in the enumeration sequence. |
| [IEnumCERTVIEWROW::Skip](https://learn.microsoft.com/windows/desktop/api/certview/nf-certview-ienumcertviewrow-skip) | Skips a specified number of rows. |

#### Examples

```cpp
#include <windows.h>
#include <stdio.h>
#include <Certview.h>

long nMax;

//  Determine the maximum row index.
hr = pRow->GetMaxIndex(&nMax);
if (FAILED(hr))
    printf("Failed GetMaxIndex [%x]\n", hr);
else
    printf("Max index is: %d\n", nMax);

```

## See also

**IEnumCERTVIEWROW**

[IEnumCERTVIEWROW::Next](https://learn.microsoft.com/windows/desktop/api/certview/nf-certview-ienumcertviewrow-next)

[IEnumCERTVIEWROW::Reset](https://learn.microsoft.com/windows/desktop/api/certview/nf-certview-ienumcertviewrow-reset)

[IEnumCERTVIEWROW::Skip](https://learn.microsoft.com/windows/desktop/api/certview/nf-certview-ienumcertviewrow-skip)