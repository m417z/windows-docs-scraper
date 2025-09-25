# SafeArrayAccessData function

## Description

Increments the lock count of an array, and retrieves a pointer to the array data.

## Parameters

### `psa` [in]

An array descriptor created by [SafeArrayCreate](https://learn.microsoft.com/previous-versions/windows/desktop/api/oleauto/nf-oleauto-safearraycreate).

### `ppvData` [out]

The array data.

## Return value

This function can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **E_INVALIDARG** | The argument *psa* is not valid. |
| **E_UNEXPECTED** | The array could not be locked. |

## Remarks

After calling **SafeArrayAccessData**, you must call the [SafeArrayUnaccessData](https://learn.microsoft.com/previous-versions/windows/desktop/api/oleauto/nf-oleauto-safearrayunaccessdata) function to unlock the array.

#### Examples

The following example sorts a safe array of one dimension that contains BSTRs by accessing the array elements directly. This approach is faster than using [SafeArrayGetElement](https://learn.microsoft.com/previous-versions/windows/desktop/api/oleauto/nf-oleauto-safearraygetelement) and [SafeArrayPutElement](https://learn.microsoft.com/previous-versions/windows/desktop/api/oleauto/nf-oleauto-safearrayputelement).

```cpp
long i, j, min;
BSTR bstrTemp;
BSTR HUGEP *pbstr;
HRESULT hr;

// Get a pointer to the elements of the array.
hr = SafeArrayAccessData(psa, (void HUGEP**)&pbstr);
if (FAILED(hr))
goto error;

// Selection sort.
for (i = 0; i < psa->rgsabound.cElements-1; i++)
{
   min = i;
   for (j = i+1; j < psa->rgsabound.cElements; j++)
   {
      if (wcscmp(pbstr[j], pbstr[min]) < 0)
         min = j;
   }

   // Swap array[min] and array[i].
   bstrTemp = pbstr[min];
   pbstr[min] = pbstr[i];
   pbstr[i] = bstrTemp;

}

SafeArrayUnaccessData(psa);
```