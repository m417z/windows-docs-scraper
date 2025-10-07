# ASSOCF enumeration

Provides information to the [**IQueryAssociations**](https://learn.microsoft.com/windows/win32/api/shlwapi/nn-shlwapi-iqueryassociations) interface methods.

## Constants

 **ASSOCF\_NONE**

None of the following options are set.

 **ASSOCF\_INIT\_NOREMAPCLSID**

Instructs [**IQueryAssociations**](https://learn.microsoft.com/windows/win32/api/shlwapi/nn-shlwapi-iqueryassociations) interface methods not to map CLSID values to ProgID values.

 **ASSOCF\_INIT\_BYEXENAME**

Identifies the value of the *pwszAssoc* parameter of [**IQueryAssociations::Init**](https://learn.microsoft.com/windows/win32/api/shlwapi/nf-shlwapi-iqueryassociations-init) as an executable file name. If this flag is not set, the root key will be set to the ProgID associated with the **.exe** key instead of the executable file's ProgID.

 **ASSOCF\_OPEN\_BYEXENAME**

Identical to **ASSOCF\_INIT\_BYEXENAME**.

 **ASSOCF\_INIT\_DEFAULTTOSTAR**

Specifies that when an [**IQueryAssociations**](https://learn.microsoft.com/windows/win32/api/shlwapi/nn-shlwapi-iqueryassociations) method does not find the requested value under the root key, it should attempt to retrieve the comparable value from the **\*** subkey.

 **ASSOCF\_INIT\_DEFAULTTOFOLDER**

Specifies that when an [**IQueryAssociations**](https://learn.microsoft.com/windows/win32/api/shlwapi/nn-shlwapi-iqueryassociations) method does not find the requested value under the root key, it should attempt to retrieve the comparable value from the **Folder** subkey.

 **ASSOCF\_NOUSERSETTINGS**

Specifies that only **HKEY\_CLASSES\_ROOT** should be searched, and that **HKEY\_CURRENT\_USER** should be ignored.

 **ASSOCF\_NOTRUNCATE**

Specifies that the return string should not be truncated. Instead, return an error value and the required size for the complete string.

 **ASSOCF\_VERIFY**

Instructs [**IQueryAssociations**](https://learn.microsoft.com/windows/win32/api/shlwapi/nn-shlwapi-iqueryassociations) methods to verify that data is accurate. This setting allows **IQueryAssociations** methods to read data from the user's hard disk for verification. For example, they can check the friendly name in the registry against the one stored in the .exe file. Setting this flag typically reduces the efficiency of the method.

 **ASSOCF\_REMAPRUNDLL**

Instructs [**IQueryAssociations**](https://learn.microsoft.com/windows/win32/api/shlwapi/nn-shlwapi-iqueryassociations) methods to ignore Rundll.exe and return information about its target. Typically **IQueryAssociations** methods return information about the first .exe or .dll in a command string. If a command uses Rundll.exe, setting this flag tells the method to ignore Rundll.exe and return information about its target.

 **ASSOCF\_NOFIXUPS**

Instructs [**IQueryAssociations**](https://learn.microsoft.com/windows/win32/api/shlwapi/nn-shlwapi-iqueryassociations) methods not to fix errors in the registry, such as the friendly name of a function not matching the one found in the .exe file.

 **ASSOCF\_IGNOREBASECLASS**

Specifies that the BaseClass value should be ignored.

 **ASSOCF\_INIT\_IGNOREUNKNOWN**

**Introduced in Windows 7**. Specifies that the "Unknown" ProgID should be ignored; instead, fail.

 **ASSOCF\_INIT\_FIXED\_PROGID**

**Introduced in Windows 8**. Specifies that the supplied ProgID should be mapped using the system defaults, rather than the current user defaults.

 **ASSOCF\_IS\_PROTOCOL**

**Introduced in Windows 8**. Specifies that the value is a protocol, and should be mapped using the current user defaults.

 **ASSOCF\_INIT\_FOR\_FILE**

**Introduced in Windows 8.1**. Specifies that the ProgID corresponds with a file extension based association. Use together with **ASSOCF\_INIT\_FIXED\_PROGID**.

 **ASSOCF\_IS\_FULL\_URI**

**Introduced in Windows 10 Anniversary Update**. Specifies that the full http/https URI is being passed for target resolution. Only one of ASSOCF_INIT_FIXED_PROGID, ASSOCF_IS_PROTOCOL, or ASSOCF_IS_FULL_URI can be specified at a time.

 **ASSOCF\_PER\_MACHINE\_ONLY**

**Introduced in Windows 10 Anniversary Update**. Enforces per-machine association look-up only and avoids **HKEY\_CURRENT\_USER**.

 **ASSOCF\_APP\_TO\_APP**

**Introduced in Windows 10 April 2018 Update**. Instructs [**IQueryAssociations**](https://learn.microsoft.com/windows/win32/api/shlwapi/nn-shlwapi-iqueryassociations) methods to include app-to-app (apps for websites, URI handlers from packaged apps) when resolving.

## Requirements

| Requirement | Value |
|-------------------------------------|--------------------------------------------------------------------------------------|
| Minimum supported client | Windows 2000 Professional, Windows XP \[desktop apps only\] |
| Minimum supported server | Windows 2000 Server \[desktop apps only\] |
| Header | Shlwapi.h |

## See also

 [**AssocQueryKey**](https://learn.microsoft.com/windows/win32/api/shlwapi/nf-shlwapi-assocquerykeya) [**AssocQueryString**](https://learn.microsoft.com/windows/win32/api/shlwapi/nf-shlwapi-assocquerystringa) [**AssocQueryStringByKey**](https://learn.microsoft.com/windows/win32/api/shlwapi/nf-shlwapi-assocquerystringa)

© 2017 Microsoft. All rights reserved.