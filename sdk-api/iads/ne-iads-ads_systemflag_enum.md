# ADS_SYSTEMFLAG_ENUM enumeration

## Description

The **ADS_SYSTEMFLAG_ENUM** enumeration defines some of the values that can be assigned to the **systemFlags** attribute. Some of the values in the enumeration are specific to **attributeSchema** objects; other values can be set on objects of any class.

## Constants

### `ADS_SYSTEMFLAG_DISALLOW_DELETE:0x80000000`

Identifies an object that cannot be deleted.

### `ADS_SYSTEMFLAG_CONFIG_ALLOW_RENAME:0x40000000`

For objects in the configuration partition, if this flag is set, the object can be renamed; otherwise, the object cannot be renamed. By default, this flag is not set on new objects created under the configuration partition, and you can set this flag only during object creation.

### `ADS_SYSTEMFLAG_CONFIG_ALLOW_MOVE:0x20000000`

For objects in the configuration partition, if this flag is set, the object can be moved; otherwise, the object cannot be moved. By default, this flag is not set on new objects created under the configuration partition, and you can set this flag only during object creation.

### `ADS_SYSTEMFLAG_CONFIG_ALLOW_LIMITED_MOVE:0x10000000`

For objects in the configuration partition, if this flag is set, the object can be moved with restrictions; otherwise, the object cannot be moved. By default, this flag is not set on new objects created under the configuration partition, and you can set this flag only during object creation.

### `ADS_SYSTEMFLAG_DOMAIN_DISALLOW_RENAME:0x8000000`

Identifies a domain object that cannot be renamed.

### `ADS_SYSTEMFLAG_DOMAIN_DISALLOW_MOVE:0x4000000`

Identifies a domain object that cannot be moved.

### `ADS_SYSTEMFLAG_CR_NTDS_NC:0x1`

Naming context is in NTDS.

### `ADS_SYSTEMFLAG_CR_NTDS_DOMAIN:0x2`

Naming context is a domain.

### `ADS_SYSTEMFLAG_ATTR_NOT_REPLICATED:0x1`

If this flag is set in the **systemFlags** attribute of an **attributeSchema** object, the attribute is not to be replicated.

### `ADS_SYSTEMFLAG_ATTR_IS_CONSTRUCTED:0x4`

If this flag is set in the **systemFlags** attribute of an **attributeSchema** object, the attribute is a constructed property.

## Remarks

For **classSchema** and **attributeSchema** objects, the 0x10 bit of the **systemFlags** attribute indicates an object that is part of the base schema included with Active Directory. This bit cannot be set on new **classSchema** and **attributeSchema** objects. The **ADS_SYSTEMFLAG_ENUM** enumeration does not include a constant for this bit.

**Note** Because VBScript cannot read data from a type library, VBScript applications do not recognize the symbolic constants as defined above. Use the numeric constants instead to set the appropriate flags in your VBScript applications. To use the symbolic constants as a good programming practice, you should make explicit declarations of such constants, as done here, in your VBScript applications.

#### Examples

The following code example shows how elements of the **ADS_SYSTEMFLAG_ENUM** enumeration, together with the [IDirectorySearch](https://learn.microsoft.com/windows/desktop/api/iads/nn-iads-idirectorysearch) interface, are used to search non-replicated properties.

```cpp
#include <wchar.h>
#include <activeds.h>
#include <atlbase.h>

HRESULT hr = E_FAIL;
LPWSTR szPrefix = L"LDAP://%s";
LPWSTR szPath = NULL;
IDirectorySearch *pSchemaNC = NULL;
IADs *pObject = NULL;
size_t nLength = 0;
LPWSTR pszSearchFilterTemplate = L"(&(objectCategory=attributeSchema)(systemFlags:1.2.840.113556.1.4.804:=%d))";
LPWSTR pszSearchFilter = NULL;

CoInitialize(NULL);     // Initialize COM

// Get rootDSE and the schema container distinguished name.
// Bind to current user's domain using current user's security context.
hr = ADsOpenObject(L"LDAP://rootDSE",
                NULL,
                NULL,
                ADS_SECURE_AUTHENTICATION, // Use Secure Authentication.
                IID_IADs,
                (void**)&pObject);
if (SUCCEEDED(hr))
{
    CComVarinat svar;
    hr = pObject->Get(CComBSTR("schemaNamingContext"), &svar);
    if (SUCCEEDED(hr))
    {
        nLength = wcslen(szPrefix) + wcslen(svar.bstrVal) + 1;
        szPath = new WCHAR[nLength];
        swprintf_s(szPath, szPrefix, svar.bstrVal);

        hr = ADsOpenObject(szPath,
            NULL,
            NULL,
            ADS_SECURE_AUTHENTICATION,
            IID_IDirectorySearch,
            (void**)&pSchemaNC);

        delete [] szPath;

        if (SUCCEEDED(hr))
        {
            wprintf(L"Find non-replicated attributes\n");

            // Create search filter to find attributes with systemFlags that
            // match ADS_SYSTEMFLAG_ATTR_NOT_REPLICATED
            nLength = wcslen(pszSearchFilterTemplate) + 25 + 1;
            pszSearchFilter = new WCHAR[nLength];
            swprintf_s(pszSearchFilter, pszSearchFilterTemplate, ADS_SYSTEMFLAG_ATTR_NOT_REPLICATED);

            // Attributes are one-level deep in the schema container
            // so only need to search one level.
            ADS_SEARCHPREF_INFO SearchPrefs;
            SearchPrefs.dwSearchPref = ADS_SEARCHPREF_SEARCH_SCOPE;
            SearchPrefs.vValue.dwType = ADSTYPE_INTEGER;
            SearchPrefs.vValue.Integer = ADS_SCOPE_ONELEVEL;
            DWORD dwNumPrefs = 1;

            // COL for iterations.
            ADS_SEARCH_COLUMN    col;

            // Handle used for searching.
            ADS_SEARCH_HANDLE hSearch;

            IADs    *pObj = NULL;
            IADs    * pIADs = NULL;

            // Set the search preference.
            hr = pSchemaNC->SetSearchPreference( &SearchPrefs, dwNumPrefs);
            if (FAILED(hr))
            {
                return hr;
            }

            CONST DWORD dwAttrNameSize = 1;
            LPOLESTR pszAttribute[dwAttrNameSize];
            pszAttribute[0] = L"cn";

            // Execute the search.
            hr = pSchemaNC->ExecuteSearch(pszSearchFilter,
                                          pszAttribute,
                                          dwAttrNameSize,
                                          &hSearch );

            delete [] pszSearchFilter;
            if ( SUCCEEDED(hr) )
            {
                // Call IDirectorySearch::GetNextRow() to retrieve
                // the next row of data.
                while( pSchemaNC->GetNextRow( hSearch) != S_ADS_NOMORE_ROWS)
                {
                    // Loop through the array of passed column names,
                    // print the data for each column.
                    for (DWORD x = 0; x < dwAttrNameSize; x++)
                    {
                        // Get the data for this column.
                        hr = pSchemaNC->GetColumn( hSearch,
                                           pszAttribute[x],
                                           &col );
                        if ( SUCCEEDED(hr) )
                        {
                            // Print the data for the column and
                            // free the column.
                            if (col.dwADsType == ADSTYPE_CASE_IGNORE_STRING)
                            {
                                wprintf(L"%s: %s\r\n",
                                pszAttribute[x],
                                col.pADsValues->CaseIgnoreString);
                            }
                            else
                            {
                                wprintf(L"<%s property is not a string>", pszAttribute[x]);
                            }

                            pSchemaNC->FreeColumn( &col );
                        }
                    }
                }

                // Close the search handle to clean up.
                pSchemaNC->CloseSearchHandle(hSearch);
            }
        }
    }

    pObject->Release();
}

CoUninitialize();    // uninitialize COM.

```

## See also

[ADSI
Enumerations](https://learn.microsoft.com/windows/desktop/ADSI/adsi-enumerations)

[IDirectorySearch](https://learn.microsoft.com/windows/desktop/api/iads/nn-iads-idirectorysearch)