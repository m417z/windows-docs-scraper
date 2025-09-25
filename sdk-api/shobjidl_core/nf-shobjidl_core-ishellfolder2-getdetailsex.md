# IShellFolder2::GetDetailsEx

## Description

Gets detailed information, identified by a property set identifier (FMTID) and a property identifier (PID), on an item in a Shell folder.

## Parameters

### `pidl` [in]

Type: **PCUITEMID_CHILD**

A PIDL of the item, relative to the parent folder. This method accepts only single-level PIDLs. The structure must contain exactly one [SHITEMID](https://learn.microsoft.com/windows/desktop/api/shtypes/ns-shtypes-shitemid) structure followed by a terminating zero. This value cannot be **NULL**.

### `pscid` [in]

Type: **const [SHCOLUMNID](https://learn.microsoft.com/windows/desktop/shell/objects)***

A pointer to an [SHCOLUMNID](https://learn.microsoft.com/windows/desktop/shell/objects) structure that identifies the column.

### `pv` [out]

Type: **VARIANT***

A pointer to a **VARIANT** with the requested information. The value is fully typed. The value returned for properties from the property system must conform to the type specified in that property definition's [typeInfo](https://learn.microsoft.com/windows/desktop/properties/propdesc-schema-typeinfo) as the *legacyType* attribute.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

This function is a more robust version of [IShellFolder2::GetDetailsOf](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-ishellfolder2-getdetailsof). It provides access to the information that is displayed in the Windows Explorer Details view of a Shell folder. The primary difference is that **GetDetailsEx** allows you to identify the column with an [FMTID](https://learn.microsoft.com/windows/desktop/shell/objects) and PID structure instead of having to first determine the column index.