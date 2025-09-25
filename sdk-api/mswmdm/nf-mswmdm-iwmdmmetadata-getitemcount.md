# IWMDMMetaData::GetItemCount

## Description

The **GetItemCount** method retrieves the total number of properties held by the interface.

## Parameters

### `iCount` [out]

Pointer to an integer that receives the total number of metadata properties stored by the interface.

## Return value

The method returns an **HRESULT**. All the interface methods in Windows Media Device Manager can return any of the following classes of error codes:

* Standard COM error codes
* Windows error codes converted to HRESULT values
* Windows Media Device Manager error codes

For an extensive list of possible error codes, see [Error Codes](https://learn.microsoft.com/windows/desktop/WMDM/error-codes).

## Remarks

This method could be used along with [QueryByIndex](https://learn.microsoft.com/windows/desktop/api/mswmdm/nf-mswmdm-iwmdmmetadata-querybyindex) to enumerate all properties on a storage or device.

#### Examples

The following code retrieves the count of properties in an **IWMDMMetaData** interface (pMetadata) and tries to retrieve them all by index and print them. It uses a custom error handling macro BREAK_HR.

```cpp

        //
        // Loop through all metadata properties, and print out the value of each.
        //
        BYTE* value;
        WMDM_TAG_DATATYPE type;
        UINT len = 0;
        UINT count = 0;
        WCHAR* name;
        // Get the number of metadata items.
        hr = pMetadata->GetItemCount(&count);

        BREAK_HR(hr, "Got a metadata count in GetMetadata.", "Couldn't get a metadata count in GetMetadata.");
        for(;count > 0; count--)
        {
            // Get the metadata property by index.
            WCHAR* name;
            hr = pMetadata->QueryByIndex(count-1, &name, &type, &value, &len);
            if (SUCCEEDED(hr))
            {
                // TODO: Display the property name.
                CoTaskMemFree(name);

                // Print out the value of the property, according to the value type.
                switch (type)
                {
                case WMDM_TYPE_QWORD:
                case WMDM_TYPE_DWORD:
                case WMDM_TYPE_WORD:
                    // TODO: Display the value.
                    break;
                case WMDM_TYPE_STRING:
                    // TODO: Display the value.
                    // Release the method-allocated property value memory.
                    if (SUCCEEDED(hr))
                        CoTaskMemFree(value);
                    break;
                case WMDM_TYPE_BOOL:
                    // TODO: Display the value.
                    break;
                case WMDM_TYPE_BINARY:
                    // TODO: Display the value.
                    break;
                case WMDM_TYPE_DATE:
                    {
                        WMDMDATETIME *val = (WMDMDATETIME*)value;
                        / /TODO: Display the month, day, and year.
                    }
                    break;
                case WMDM_TYPE_GUID:
                    {
                        WCHAR strGuid[64];
                        StringFromGUID2(reinterpret_cast<GUID&>(value),(LPOLESTR)strGuid, 64);
                        / /TODO: Display the GUID.
                    }
                    break;
                default:
                    // TODO: Display a message indicating that the
                    // application could not understand the returned value type.
                }
            }
            else // Couldn't get the metadata property at index count - 1.
                // TODO: Display a message indicating that the
                // application couldn't retrieve a value for the index.
        // Clear the WMDM-allocated memory.
        if (value)
            CoTaskMemFree(value);
        }

```

## See also

[IWMDMMetaData Interface](https://learn.microsoft.com/windows/desktop/api/mswmdm/nn-mswmdm-iwmdmmetadata)

[Metadata Constants](https://learn.microsoft.com/windows/desktop/WMDM/metadata-constants)

[QueryByIndex](https://learn.microsoft.com/windows/desktop/api/mswmdm/nf-mswmdm-iwmdmmetadata-querybyindex)

[Setting Metadata on a File](https://learn.microsoft.com/windows/desktop/WMDM/setting-metadata-on-a-file)