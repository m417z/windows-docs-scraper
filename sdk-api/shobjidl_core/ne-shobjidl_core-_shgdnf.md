# _SHGDNF enumeration

## Description

Defines the values used with the [IShellFolder::GetDisplayNameOf](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-ishellfolder-getdisplaynameof) and [IShellFolder::SetNameOf](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-ishellfolder-setnameof) methods to specify the type of file or folder names used by those methods.

**Note** Prior to Windows 7, these values were packaged as the SHGNO enumeration.

## Constants

### `SHGDN_NORMAL:0`

When not combined with another flag, return the parent-relative name that identifies the item, suitable for displaying to the user. This name often does not include extra information such as the file name extension and does not need to be unique. This name might include information that identifies the folder that contains the item. For instance, this flag could cause [IShellFolder::GetDisplayNameOf](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-ishellfolder-getdisplaynameof) to return the string "**username** (on **Machine**)" for a particular user's folder.

### `SHGDN_INFOLDER:0x1`

The name is relative to the folder from which the request was made. This is the name display to the user when used in the context of the folder. For example, it is used in the view and in the address bar path segment for the folder. This name should not include disambiguation information—for instance "**username**" instead of "**username** (on *Machine*)" for a particular user's folder.

Use this flag in combinations with [SHGDN_FORPARSING](https://learn.microsoft.com/windows/win32/api/shobjidl_core/ne-shobjidl_core-_shgdnf) and [SHGDN_FOREDITING](https://learn.microsoft.com/windows/win32/api/shobjidl_core/ne-shobjidl_core-_shgdnf).

### `SHGDN_FOREDITING:0x1000`

The name is used for in-place editing when the user renames the item.

### `SHGDN_FORADDRESSBAR:0x4000`

The name is displayed in an address bar combo box.

### `SHGDN_FORPARSING:0x8000`

The name is used for parsing. That is, it can be passed to [IShellFolder::ParseDisplayName](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-ishellfolder-parsedisplayname) to recover the object's PIDL. The form this name takes depends on the particular object. When SHGDN_FORPARSING is used alone, the name is relative to the desktop. When combined with SHGDN_INFOLDER, the name is relative to the folder from which the request was made.

## Remarks

The **SHGDNF** type is defined in Shobjidl.h as shown here.

```
typedef DWORD SHGDNF;
```

This enumeration consists of two groups of values. The first group—SHGDN_NORMAL and SHGDN_INFOLDER—specifies the name's type. The second group—SHGDN_FOREDITING, SHGDN_FORADDRESSBAR, and SHGDN_FORPARSING—consists of modifiers to the first group that specify name retrieval options.

If SHGDN_FORPARSING is set and SHGDN_INFOLDER is not set, [IShellFolder::GetDisplayNameOf](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-ishellfolder-getdisplaynameof) can accept a PIDL that contains more than an [SHITEMID](https://learn.microsoft.com/windows/desktop/api/shtypes/ns-shtypes-shitemid) structure. Otherwise, only a single-level PIDL can be passed.

**Note** While the parsing name returned by file system objects is the object's fully qualified path, virtual folders might use something quite different. For example, some virtual folders use a GUID as the parsing name and return a string of the form "::{GUID}". To check whether the object is part of the file system, call [IShellFolder::GetAttributesOf](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-ishellfolder-getattributesof) and see if the **SFGAO_FILESYSTEM** flag is set. Developers who implement [IShellFolder::GetDisplayNameOf](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-ishellfolder-getdisplaynameof) are encouraged to return parse names that are as close to the display names as possible, because the end user often needs to type or edit these names.

The numeric value of SHGDN_NORMAL is zero, so you cannot test for the presence of this bit. Consider SHGDN_NORMAL a default setting that is used if no other flag in that group is set.

**Example**

The following tables illustrate an example of possible return values for five different flag options and three different item types.

These are the flag options.

| Number | Flags | Description |
| --- | --- | --- |
| 1 | SHGDN_FORPARSING | Returns the fully qualified parsing name. |
| 2 | SHGDN_INFOLDER \| SHGDN_FORPARSING | Returns the parsing name relative to the parent folder. |
| 3 | SHGDN_INFOLDER \| SHGDN_FOREDITING | Returns the editing name relative to the parent folder. |
| 4 | SHGDN_INFOLDER | Returns the display name relative to the parent folder. |
| 5 | SHGDN_NORMAL | Returns the display name relative to the desktop and not to a specific folder. |

These are the sample item types.

| Letter | Description |
| --- | --- |
| A | The C: drive on the local computer, whose volume label is C_DRIVE. |
| B | A printer named Laser on a computer called Mailroom. |
| C | The file C:\Directory\File.txt (when file-name extensions are hidden). |

The following table describes the display names as they would be returned.

|  | A | B | C |
| --- | --- | --- | --- |
| 1 | C:\ | \\Mailroom\Laser | C:\Directory\File.txt |
| 2 | C:\ | Laser | File.txt |
| 3 | C_DRIVE | Laser | File |
| 4 | C_DRIVE (C:) | Laser | File |
| 5 | C_DRIVE (C:) | Laser on Mailroom | File |

**Remarks on examples**

* A3: The C: drive presents its volume name for editing, rather than the entire string "C_DRIVE (C:)".
* B1-B5: The display name of the remote printer changes depending on whether it is being shown relative to its parent. When shown relative to its parent, it needs only its printer name, but when shown outside its parent, it shows both its printer name and its computer name.
* C3: File.txt presents only its base name for editing instead of its full name.

For further discussion of the [IShellFolder](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellfolder) interface, see [Getting Information About the Contents of a Folder](https://learn.microsoft.com/windows/desktop/shell/folder-info).