# TAG macro

## Description

Identifies an entry in the shim database.

The following entries are of type **TAG_TYPE_LIST** (0x7000).

| Constant/value | Description |
| --- | --- |
| **TAG_DATABASE**<br><br>(0x1 \| **TAG_TYPE_LIST**) | Database entry. |
| **TAG_LIBRARY**<br><br>(0x2 \| **TAG_TYPE_LIST**) | Library entry. |
| **TAG_INEXCLUDE**<br><br>(0x3 \| **TAG_TYPE_LIST**) | Include and exclude entry. |
| **TAG_SHIM**<br><br>(0x4 \| **TAG_TYPE_LIST**) | Shim entry that contains the name and purpose information. |
| **TAG_PATCH**<br><br>(0x5 \| **TAG_TYPE_LIST**) | Patch entry that contains the in-memory patching information. |
| **TAG_APP**<br><br>(0x6 \| **TAG_TYPE_LIST**) | Application entry. |
| **TAG_EXE**<br><br>(0x7 \| **TAG_TYPE_LIST**) | Executable entry. |
| **TAG_MATCHING_FILE**<br><br>(0x8 \| **TAG_TYPE_LIST**) | Matching file entry. |
| **TAG_SHIM_REF**<br><br>(0x9\| TAG_TYPE_LIST) | Shim definition entry. |
| **TAG_PATCH_REF**<br><br>(0xA \| **TAG_TYPE_LIST**) | Patch definition entry. |
| **TAG_LAYER**<br><br>(0xB \| **TAG_TYPE_LIST**) | Layer shim entry. |
| **TAG_FILE**<br><br>(0xC \| **TAG_TYPE_LIST**) | File attribute used in a shim entry. |
| **TAG_APPHELP**<br><br>(0xD \| **TAG_TYPE_LIST**) | Apphelp information entry. |
| **TAG_LINK**<br><br>(0xE \| **TAG_TYPE_LIST**) | Apphelp online link information entry. |
| **TAG_DATA**<br><br>(0xF \| **TAG_TYPE_LIST**) | Name-value mapping entry. |
| **TAG_MSI_TRANSFORM**<br><br>(0x10 \| **TAG_TYPE_LIST**) | MSI transformation entry. |
| **TAG_MSI_TRANSFORM_REF**<br><br>(0x11 \| **TAG_TYPE_LIST**) | MSI transformation definition entry. |
| **TAG_MSI_PACKAGE**<br><br>(0x12 \| **TAG_TYPE_LIST**) | MSI package entry. |
| **TAG_FLAG**<br><br>(0x13 \| **TAG_TYPE_LIST**) | Flag entry. |
| **TAG_MSI_CUSTOM_ACTION**<br><br>(0x14 \| **TAG_TYPE_LIST**) | MSI custom action entry. |
| **TAG_FLAG_REF**<br><br>(0x15 \| **TAG_TYPE_LIST**) | Flag definition entry. |
| **TAG_ACTION**<br><br>(0x16 \| **TAG_TYPE_LIST**) | Unused. |
| **TAG_LOOKUP**<br><br>(0x17 \| **TAG_TYPE_LIST**) | Lookup entry used for lookup in a driver database. |
| **TAG_STRINGTABLE**<br><br>(0x801 \| **TAG_TYPE_LIST**) | String table entry. |
| **TAG_INDEXES**<br><br>(0x802 \| **TAG_TYPE_LIST**) | Indexes entry that defines all the indexes in a shim database. |
| **TAG_INDEX**<br><br>(0x803 \| **TAG_TYPE_LIST**) | Index entry that defines an index in a shim database. |

The following entries are of type **TAG_TYPE_STRINGREF** (0x6000).

| Constant/value | Description |
| --- | --- |
| **TAG_NAME**<br><br>(0x1 \| **TAG_TYPE_STRINGREF**) | Name attribute. |
| **TAG_DESCRIPTION**<br><br>(0x2 \| **TAG_TYPE_STRINGREF**) | Description entry. |
| **TAG_MODULE**<br><br>(0x3 \| **TAG_TYPE_STRINGREF**) | Module attribute. |
| **TAG_API**<br><br>(0x4 \| **TAG_TYPE_STRINGREF**) | API entry. |
| **TAG_VENDOR**<br><br>(0x5 \| **TAG_TYPE_STRINGREF**) | Vendor name attribute. |
| **TAG_APP_NAME**<br><br>(0x6 \| **TAG_TYPE_STRINGREF**) | Application name attribute that describes an application entry in a shim database. |
| **TAG_COMMAND_LINE**<br><br>(0x8 \| **TAG_TYPE_STRINGREF**) | Command line attribute that is used when passing arguments to a shim, for example. |
| **TAG_COMPANY_NAME**<br><br>(0x9 \| **TAG_TYPE_STRINGREF**) | Company name attribute. |
| **TAG_DLLFILE**<br><br>(0xA \| **TAG_TYPE_STRINGREF**) | DLL file attribute for a shim entry. |
| **TAG_WILDCARD_NAME**<br><br>(0xB \| **TAG_TYPE_STRINGREF**) | Wildcard name attribute for an executable entry with a wildcard as the file name. |
| **TAG_PRODUCT_NAME**<br><br>(0x10 \| **TAG_TYPE_STRINGREF**) | Product name attribute. |
| **TAG_PRODUCT_VERSION**<br><br>(0x11 \| **TAG_TYPE_STRINGREF**) | Product version attribute. |
| **TAG_FILE_DESCRIPTION**<br><br>(0x12 \| **TAG_TYPE_STRINGREF**) | File description attribute. |
| **TAG_FILE_VERSION**<br><br>(0x13 \| **TAG_TYPE_STRINGREF**) | File version attribute. |
| **TAG_ORIGINAL_FILENAME**<br><br>(0x14 \| **TAG_TYPE_STRINGREF**) | Original file name attribute. |
| **TAG_INTERNAL_NAME**<br><br>(0x15 \| **TAG_TYPE_STRINGREF**) | Internal file name attribute. |
| **TAG_LEGAL_COPYRIGHT**<br><br>(0x16 \| **TAG_TYPE_STRINGREF**) | Copyright attribute. |
| **TAG_16BIT_DESCRIPTION**<br><br>(0x17 \| **TAG_TYPE_STRINGREF**) | 16-bit description attribute. |
| **TAG_APPHELP_DETAILS**<br><br>(0x18 \| **TAG_TYPE_STRINGREF**) | Apphelp details message information attribute. |
| **TAG_LINK_URL**<br><br>(0x19 \| **TAG_TYPE_STRINGREF**) | Apphelp online link URL attribute. |
| **TAG_LINK_TEXT**<br><br>(0x1A \| **TAG_TYPE_STRINGREF**) | Apphelp online link text attribute. |
| **TAG_APPHELP_TITLE**<br><br>(0x1B \| **TAG_TYPE_STRINGREF**) | Apphelp title attribute. |
| **TAG_APPHELP_CONTACT**<br><br>(0x1C \| **TAG_TYPE_STRINGREF**) | Apphelp vendor contact attribute. |
| **TAG_SXS_MANIFEST**<br><br>(0x1D \| **TAG_TYPE_STRINGREF**) | Side-by-side manifest entry. |
| **TAG_DATA_STRING**<br><br>(0x1E \| **TAG_TYPE_STRINGREF**) | String attribute for a data entry. |
| **TAG_MSI_TRANSFORM_FILE**<br><br>(0x1F \| **TAG_TYPE_STRINGREF**) | File name attribute of an MSI transformation entry. |
| **TAG_16BIT_MODULE_NAME**<br><br>(0x20 \| **TAG_TYPE_STRINGREF**) | 16-bit module name attribute. |
| **TAG_LAYER_DISPLAYNAME**<br><br>(0x21 \| **TAG_TYPE_STRINGREF**) | Unused. |
| **TAG_COMPILER_VERSION**<br><br>(0x22 \| **TAG_TYPE_STRINGREF**) | Shim database compiler version. |
| **TAG_ACTION_TYPE**<br><br>(0x23 \| **TAG_TYPE_STRINGREF**) | Unused. |
| **TAG_EXPORT_NAME**<br><br>(0x24 \| **TAG_TYPE_STRINGREF**) | Export file name attribute. |

The following entries are of type **TAG_TYPE_DWORD** (0x4000).

| Constant/value | Description |
| --- | --- |
| **TAG_SIZE**<br><br>(0x1 \| **TAG_TYPE_DWORD**) | File size attribute. |
| **TAG_OFFSET**<br><br>(0x2 \| **TAG_TYPE_DWORD**) | Unused. |
| **TAG_CHECKSUM**<br><br>(0x3 \| **TAG_TYPE_DWORD**) | File checksum attribute. |
| **TAG_SHIM_TAGID**<br><br>(0x4 \| **TAG_TYPE_DWORD**) | Shim **TAGID** attribute. |
| **TAG_PATCH_TAGID**<br><br>(0x5 \| **TAG_TYPE_DWORD**) | Patch **TAGID** attribute. |
| **TAG_MODULE_TYPE**<br><br>(0x6 \| **TAG_TYPE_DWORD**) | Module type attribute. |
| **TAG_VERDATEHI**<br><br>(0x7 \| **TAG_TYPE_DWORD**) | High-order portion of the file version date attribute. |
| **TAG_VERDATELO**<br><br>(0x8 \| **TAG_TYPE_DWORD**) | Low-order portion of the file version date attribute. |
| **TAG_VERFILEOS**<br><br>(0x9 \| **TAG_TYPE_DWORD**) | Operating system file version attribute. |
| **TAG_VERFILETYPE**<br><br>(0xA \| **TAG_TYPE_DWORD**) | File type attribute. |
| **TAG_PE_CHECKSUM**<br><br>(0xB \| **TAG_TYPE_DWORD**) | PE file checksum attribute. |
| **TAG_PREVOSMAJORVER**<br><br>(0xC \| **TAG_TYPE_DWORD**) | Major operating system version attribute. |
| **TAG_PREVOSMINORVER**<br><br>(0xD \| **TAG_TYPE_DWORD**) | Minor operating system version attribute. |
| **TAG_PREVOSPLATFORMID**<br><br>(0xE \| **TAG_TYPE_DWORD**) | Operating system platform identifier attribute. |
| **TAG_PREVOSBUILDNO**<br><br>(0xF \| **TAG_TYPE_DWORD**) | Operating system build number attribute. |
| **TAG_PROBLEMSEVERITY**<br><br>(0x10 \| **TAG_TYPE_DWORD**) | Block attribute of an Apphelp entry. This determines whether the application is hard or soft blocked. |
| **TAG_LANGID**<br><br>(0x11 \| **TAG_TYPE_DWORD**) | Language identifier of an Apphelp entry. |
| **TAG_VER_LANGUAGE**<br><br>(0x12 \| **TAG_TYPE_DWORD**) | Language version attribute of a file. |
| **TAG_ENGINE**<br><br>(0x14 \| **TAG_TYPE_DWORD**) | Unused. |
| **TAG_HTMLHELPID**<br><br>(0x15 \| **TAG_TYPE_DWORD**) | Help identifier attribute for an Apphelp entry. |
| **TAG_INDEX_FLAGS**<br><br>(0x16 \| **TAG_TYPE_DWORD**) | Flags attribute for an index entry. |
| **TAG_FLAGS**<br><br>(0x17 \| **TAG_TYPE_DWORD**) | Flags attribute for an Apphelp entry. |
| **TAG_DATA_VALUETYPE**<br><br>(0x18 \| **TAG_TYPE_DWORD**) | Data type attribute for a data entry. |
| **TAG_DATA_DWORD**<br><br>(0x19 \| **TAG_TYPE_DWORD**) | **DWORD** value attribute for a data entry. |
| **TAG_LAYER_TAGID**<br><br>(0x1A \| **TAG_TYPE_DWORD**) | Layer shim **TAGID** attribute. |
| **TAG_MSI_TRANSFORM_TAGID**<br><br>(0x1B \| **TAG_TYPE_DWORD**) | MSI transform **TAGID** attribute. |
| **TAG_LINKER_VERSION**<br><br>(0x1C \| **TAG_TYPE_DWORD**) | Linker version attribute of a file. |
| **TAG_LINK_DATE**<br><br>(0x1D \| **TAG_TYPE_DWORD**) | Link date attribute of a file. |
| **TAG_UPTO_LINK_DATE**<br><br>(0x1E \| **TAG_TYPE_DWORD**) | Link date attribute of a file. Matching is done up to and including this link date. |
| **TAG_OS_SERVICE_PACK**<br><br>(0x1F \| **TAG_TYPE_DWORD**) | Operating system service pack attribute for an executable entry. |
| **TAG_FLAG_TAGID**<br><br>(0x20 \| **TAG_TYPE_DWORD**) | Flags **TAGID** attribute. |
| **TAG_RUNTIME_PLATFORM**<br><br>(0x21 \| **TAG_TYPE_DWORD**) | Run-time platform attribute of a file. |
| **TAG_OS_SKU**<br><br>(0x22 \| **TAG_TYPE_DWORD**) | Operating system SKU attribute for an executable entry. |
| **TAG_OS_PLATFORM**<br><br>(0x23 \| **TAG_TYPE_DWORD**) | Operating system platform attribute. |
| **TAG_APP_NAME_RC_ID**<br><br>(0x24 \| **TAG_TYPE_DWORD**) | Application name resource identifier attribute for Apphelp entries. |
| **TAG_VENDOR_NAME_RC_ID**<br><br>(0x25 \| **TAG_TYPE_DWORD**) | Vendor name resource identifier attribute for Apphelp entries. |
| **TAG_SUMMARY_MSG_RC_ID**<br><br>(0x26 \| **TAG_TYPE_DWORD**) | Summary message resource identifier attribute for Apphelp entries. |
| **TAG_VISTA_SKU**<br><br>(0x27 \| **TAG_TYPE_DWORD**) | Windows Vista SKU attribute. |
| **TAG_DESCRIPTION_RC_ID**<br><br>(0x28 \| **TAG_TYPE_DWORD**) | Description resource identifier attribute for Apphelp entries. |
| **TAG_PARAMETER1_RC_ID**<br><br>(0x29 \| **TAG_TYPE_DWORD**) | Parameter1 resource identifier attribute for Apphelp entries. |
| **TAG_TAGID**<br><br>(0x801 \| **TAG_TYPE_DWORD**) | **TAGID** attribute. |

The following entry is of type **TAG_TYPE_STRING** (0x8000).

| Constant/value | Description |
| --- | --- |
| **TAG_STRINGTABLE_ITEM**<br><br>(0x801 \| **TAG_TYPE_STRING**) | String table item entry. |

The following entries are of type **TAG_TYPE_NULL** (0x1000).

| Constant/value | Description |
| --- | --- |
| **TAG_INCLUDE**<br><br>(0x1 \| **TAG_TYPE_NULL**) | Include list entry. |
| **TAG_GENERAL**<br><br>(0x2 \| **TAG_TYPE_NULL**) | General purpose shim entry. |
| **TAG_MATCH_LOGIC_NOT**<br><br>(0x3 \| **TAG_TYPE_NULL**) | NOT of matching logic entry. |
| **TAG_APPLY_ALL_SHIMS**<br><br>(0x4 \| **TAG_TYPE_NULL**) | Unused. |
| **TAG_USE_SERVICE_PACK_FILES**<br><br>(0x5 \| **TAG_TYPE_NULL**) | Service pack information for Apphelp entries. |
| **TAG_MITIGATION_OS**<br><br>(0x6 \| **TAG_TYPE_NULL**) | Mitigation at operating system scope entry. |
| **TAG_BLOCK_UPGRADE**<br><br>(0x7 \| **TAG_TYPE_NULL**) | Upgrade block entry. |
| **TAG_INCLUDEEXCLUDEDLL**<br><br>(0x8 \| **TAG_TYPE_NULL**) | DLL include/exclude entry. |

The following entries are of type **TAG_TYPE_QWORD** (0x5000).

| Constant/value | Description |
| --- | --- |
| **TAG_TIME**<br><br>(0x1 \| **TAG_TYPE_QWORD**) | Time attribute. |
| **TAG_BIN_FILE_VERSION**<br><br>(0x2 \| **TAG_TYPE_QWORD**) | Bin file version attribute for file entries. |
| **TAG_BIN_PRODUCT_VERSION**<br><br>(0x3 \| **TAG_TYPE_QWORD**) | Bin product version attribute for file entries. |
| **TAG_MODTIME**<br><br>(0x4 \| **TAG_TYPE_QWORD**) | Unused. |
| **TAG_FLAG_MASK_KERNEL**<br><br>(0x5 \| **TAG_TYPE_QWORD**) | Kernel flag mask attribute. |
| **TAG_UPTO_BIN_PRODUCT_VERSION**<br><br>(0x6 \| **TAG_TYPE_QWORD**) | Bin product version attribute of a file. Matching is done up to and including this product version. |
| **TAG_DATA_QWORD**<br><br>(0x7 \| **TAG_TYPE_QWORD**) | **ULONGLONG** value attribute for a data entry. |
| **TAG_FLAG_MASK_USER**<br><br>(0x8 \| **TAG_TYPE_QWORD**) | User flag mask attribute. |
| **TAG_FLAGS_NTVDM1**<br><br>(0x9 \| **TAG_TYPE_QWORD**) | NTVDM1 flag mask attribute. |
| **TAG_FLAGS_NTVDM2**<br><br>(0xA \| **TAG_TYPE_QWORD**) | NTVDM2 flag mask attribute. |
| **TAG_FLAGS_NTVDM3**<br><br>(0xB \| **TAG_TYPE_QWORD**) | NTVDM3 flag mask attribute. |
| **TAG_FLAG_MASK_SHELL**<br><br>(0xC \| **TAG_TYPE_QWORD**) | Shell flag mask attribute. |
| **TAG_UPTO_BIN_FILE_VERSION**<br><br>(0xD \| **TAG_TYPE_QWORD**) | Bin file version attribute of a file. Matching is done up to and including this file version. |
| **TAG_FLAG_MASK_FUSION**<br><br>(0xE \| **TAG_TYPE_QWORD**) | Fusion flag mask attribute. |
| **TAG_FLAG_PROCESSPARAM**<br><br>(0xF \| **TAG_TYPE_QWORD**) | Process param flag attribute. |
| **TAG_FLAG_LUA**<br><br>(0x10 \| **TAG_TYPE_QWORD**) | LUA flag attribute. |
| **TAG_FLAG_INSTALL**<br><br>(0x11 \| **TAG_TYPE_QWORD**) | Install flag attribute. |

The following entries are of type **TAG_TYPE_BINARY** (0x9000).

| Constant/value | Description |
| --- | --- |
| **TAG_PATCH_BITS**<br><br>(0x2 \| **TAG_TYPE_BINARY**) | Patch file bits attribute. |
| **TAG_FILE_BITS**<br><br>(0x3 \| **TAG_TYPE_BINARY**) | File bits attribute. |
| **TAG_EXE_ID**<br><br>(0x4 \| **TAG_TYPE_BINARY**) | **GUID** attribute of an executable entry. |
| **TAG_DATA_BITS**<br><br>(0x5 \| **TAG_TYPE_BINARY**) | Data bits attribute. |
| **TAG_MSI_PACKAGE_ID**<br><br>(0x6 \| **TAG_TYPE_BINARY**) | MSI package identifier attribute of an MSI package. |
| **TAG_DATABASE_ID**<br><br>(0x7 \| **TAG_TYPE_BINARY**) | **GUID** attribute of a database. |
| **TAG_INDEX_BITS**<br><br>(0x801 \| **TAG_TYPE_BINARY**) | Index bits attribute. |

The following entries are of type **TAG_TYPE_WORD** (0x3000).

| Constant/value | Description |
| --- | --- |
| **TAG_MATCH_MODE**<br><br>(0x1 \| **TAG_TYPE_WORD**) | Match mode attribute. |
| **TAG_TAG**<br><br>(0x801 \| **TAG_TYPE_WORD**) | TAG entry. |
| **TAG_INDEX_TAG**<br><br>(0x802 \| **TAG_TYPE_WORD**) | Index TAG attribute for an index entry. |
| **TAG_INDEX_KEY**<br><br>(0x803 \| **TAG_TYPE_WORD**) | Index key attribute for an index entry. |

## Parameters

## See also

[TAG Types](https://learn.microsoft.com/windows/desktop/DevNotes/tag-types)

[TAGID](https://learn.microsoft.com/windows/desktop/DevNotes/tagid)

[TAGREF](https://learn.microsoft.com/windows/desktop/DevNotes/tagref)