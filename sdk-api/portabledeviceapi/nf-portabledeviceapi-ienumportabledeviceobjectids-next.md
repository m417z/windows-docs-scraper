# IEnumPortableDeviceObjectIDs::Next

## Description

The **Next** method retrieves the next one or more object IDs in the enumeration sequence.

## Parameters

### `cObjects` [in]

A count of the objects requested.

### `pObjIDs` [in, out]

An array of **LPWSTR** pointers, each specifying a retrieved object ID. The caller must allocate an array of *cObjects* LPWSTR elements. The caller must free both the array and the returned strings. The strings are freed by calling [CoTaskMemFree](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cotaskmemfree).

### `pcFetched` [in, out]

On input, this parameter is ignored. On output, the number of IDs actually retrieved. If no object IDs are released and the return value is S_FALSE, there are no more objects to enumerate.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **S_FALSE** | There are no more objects to enumerate. |

## Remarks

If fewer than the requested number of elements remain in the sequence, this method retrieves the remaining elements. The number of elements that are actually retrieved is returned through *pcFetched* (unless the caller passed in NULL for that parameter). Enumerated objects are all peers—that is, enumerating children of an object will enumerate only direct children, not grandchild or deeper objects.

#### Examples

```cpp

// This number controls how many object identifiers are requested during each call
// to IEnumPortableDeviceObjectIDs::Next()
#define NUM_OBJECTS_TO_REQUEST  10

// Recursively called function which enumerates using the specified
// object identifier as the parent.
void RecursiveEnumerate(LPCWSTR wszParentObjectID, IPortableDeviceContent* pContent)
{
    HRESULT                       hr             = S_OK;
    IEnumPortableDeviceObjectIDs* pEnumObjectIDs = NULL;

    if ((wszParentObjectID == NULL) ||
        (pContent          == NULL))
    {
        return;
    }

    // wszParentObjectID is the object identifier of the parent being used for enumeration

    // Get an IEnumPortableDeviceObjectIDs interface by calling EnumObjects with the
    // specified parent object identifier.
    hr = pContent->EnumObjects(0, wszParentObjectID, NULL, &pEnumObjectIDs);
    if (FAILED(hr))
    {
        // Failed to get IEnumPortableDeviceObjectIDs from IPortableDeviceContent
    }

    // Loop calling Next() while S_OK is being returned.
    while(hr == S_OK)
    {
        DWORD  cFetched = 0;
        LPWSTR szObjectIDArray[NUM_OBJECTS_TO_REQUEST] = {0};
        hr = pEnumObjectIDs->Next(NUM_OBJECTS_TO_REQUEST, // Number of objects to request on each NEXT call
                                  szObjectIDArray,        // Array of LPWSTR array which will be populated on each NEXT call
                                  &cFetched);             // Number of objects written to the LPWSTR array
        if (SUCCEEDED(hr))
        {
            // Traverse the results of the Next() operation and recursively enumerate
            // Remember to free all returned object identifiers using CoTaskMemFree()
            for (DWORD dwIndex = 0; dwIndex < cFetched; dwIndex++)
            {
                RecursiveEnumerate(szObjectIDArray[dwIndex],pContent);

                // Free allocated LPWSTRs after the recursive enumeration call has completed.
                CoTaskMemFree(szObjectIDArray[dwIndex]);
                szObjectIDArray[dwIndex] = NULL;
            }
        }
    }

    // Release the IEnumPortableDeviceObjectIDs when finished
    if (pEnumObjectIDs != NULL)
    {
        pEnumObjectIDs->Release();
        pEnumObjectIDs = NULL;
    }
}

```

## See also

[Enumerating Content](https://learn.microsoft.com/windows/desktop/wpd_sdk/enumerating-content)

[IEnumPortableDeviceObjectIDs Interface](https://learn.microsoft.com/windows/desktop/api/portabledeviceapi/nn-portabledeviceapi-ienumportabledeviceobjectids)