# _SHCONTF enumeration

## Description

Determines the types of items included in an enumeration. These values are used with the [IShellFolder::EnumObjects](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-ishellfolder-enumobjects) method.

## Constants

### `SHCONTF_CHECKING_FOR_CHILDREN:0x10`

0x00010. **Windows 7 and later**. The calling application is checking for the existence of child items in the folder.

### `SHCONTF_FOLDERS:0x20`

0x00020. Include items that are folders in the enumeration.

### `SHCONTF_NONFOLDERS:0x40`

0x00040. Include items that are not folders in the enumeration.

### `SHCONTF_INCLUDEHIDDEN:0x80`

0x00080. Include hidden items in the enumeration. This does not include hidden system items. (To include hidden system items, use SHCONTF_INCLUDESUPERHIDDEN.)

### `SHCONTF_INIT_ON_FIRST_NEXT:0x100`

0x00100. No longer used; always assumed. [IShellFolder::EnumObjects](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-ishellfolder-enumobjects) can return without validating the enumeration object. Validation can be postponed until the first call to [IEnumIDList::Next](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-ienumidlist-next). Use this flag when a user interface might be displayed prior to the first **IEnumIDList::Next** call. For a user interface to be presented, *hwnd* must be set to a valid window handle.

### `SHCONTF_NETPRINTERSRCH:0x200`

0x00200. The calling application is looking for printer objects.

### `SHCONTF_SHAREABLE:0x400`

0x00400. The calling application is looking for resources that can be shared.

### `SHCONTF_STORAGE:0x800`

0x00800. Include items with accessible storage and their ancestors, including hidden items.

### `SHCONTF_NAVIGATION_ENUM:0x1000`

0x01000. **Windows 7 and later**. Child folders should provide a navigation enumeration.

### `SHCONTF_FASTITEMS:0x2000`

0x02000. **Windows Vista and later**. The calling application is looking for resources that can be enumerated quickly.

### `SHCONTF_FLATLIST:0x4000`

0x04000. **Windows Vista and later**. Obsolete. Do not use.

### `SHCONTF_ENABLE_ASYNC:0x8000`

0x08000. **Windows Vista and later**. The calling application is monitoring for change notifications. This means that the enumerator does not have to return all results. Items can be reported through change notifications.

### `SHCONTF_INCLUDESUPERHIDDEN:0x10000`

0x10000. **Windows 7 and later**. Include hidden system items in the enumeration. This value does not include hidden non-system items. (To include hidden non-system items, use SHCONTF_INCLUDEHIDDEN.)

## Remarks

By setting the **SHCONTF_INIT_ON_FIRST_NEXT** flag, the calling application suggests that the [IShellFolder::EnumObjects](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-ishellfolder-enumobjects) method can expedite the enumeration process by returning an uninitialized enumeration object. Initialization can be deferred until the enumeration process starts. If initializing the enumeration object is a lengthy process, the method implementation should immediately return an uninitialized object. Defer initialization until the first time the [IEnumIDList::Next](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-ienumidlist-next) method is called. If initialization requires user input, the method implementation should use *hwnd* as the parent window for the user interface. For an explanation of what to do when *hwnd* is set to **NULL**, see the **IShellFolder::EnumObjects** reference.

**Note** The name of this enumeration was changed to **_SHCONTF** in Windows Vista. Earlier, it was named **tagSHCONTF**. For compatibility with legacy code, the name **SHCONTF** is defined through a typedef statement to be a synonym for **DWORD**.