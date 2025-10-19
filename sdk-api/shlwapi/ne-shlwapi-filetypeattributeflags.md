# FILETYPEATTRIBUTEFLAGS enumeration

## Description

Indicates **FILETYPEATTRIBUTEFLAGS** constants that are used in the EditFlags value of a file association [PROGID](https://learn.microsoft.com/windows/desktop/shell/fa-progids) registry key.

## Constants

### `FTA_None:0x00000000`

No [FILETYPEATTRIBUTEFLAGS](https://learn.microsoft.com/windows/desktop/api/shlwapi/ne-shlwapi-filetypeattributeflags) options set.

### `FTA_Exclude:0x00000001`

Excludes the file type.

### `FTA_Show:0x00000002`

Shows file types, such as folders, that are not associated with a file name extension.

### `FTA_HasExtension:0x00000004`

Indicates that the file type has a file name extension.

### `FTA_NoEdit:0x00000008`

Prohibits editing of the registry entries associated with this file type, the addition of new entries, and the deletion or modification of existing entries.

### `FTA_NoRemove:0x00000010`

Prohibits deletion of the registry entries associated with this file type.

### `FTA_NoNewVerb:0x00000020`

Prohibits the addition of new [verbs](https://learn.microsoft.com/windows/desktop/shell/fa-verbs) to the file type.

### `FTA_NoEditVerb:0x00000040`

Prohibits the modification or deletion of canonical [verbs](https://learn.microsoft.com/windows/desktop/shell/fa-verbs) such as **open** and **print**.

### `FTA_NoRemoveVerb:0x00000080`

Prohibits the deletion of canonical verbs such as **open** and **print**.

### `FTA_NoEditDesc:0x00000100`

Prohibits the modification or deletion of the description of the file type.

### `FTA_NoEditIcon:0x00000200`

Prohibits the modification or deletion of the [icon](https://learn.microsoft.com/windows/desktop/shell/icon) assigned to the file type.

### `FTA_NoEditDflt:0x00000400`

Prohibits the modification of the [default verb](https://learn.microsoft.com/windows/desktop/shell/fa-verbs).

### `FTA_NoEditVerbCmd:0x00000800`

Prohibits the modification of the [commands](https://learn.microsoft.com/windows/desktop/shell/fa-verbs) associated with verbs.

### `FTA_NoEditVerbExe:0x00001000`

Prohibits the modification or deletion of verbs.

### `FTA_NoDDE:0x00002000`

Prohibits the modification or deletion of the entries related to DDE.

### `FTA_NoEditMIME:0x00008000`

Prohibits the modification or deletion of the content type and default extension entries.

### `FTA_OpenIsSafe:0x00010000`

Indicates that the file type's **open** verb can be safely invoked for downloaded files. This flag applies only to safe file types, as identified by [AssocIsDangerous](https://learn.microsoft.com/windows/desktop/api/shlwapi/nf-shlwapi-associsdangerous). To improve the user experience and reduce unnecessary user prompts when downloading and activating items, file type owners should specify this flag and applications that download and activate files should respect this flag.

### `FTA_AlwaysUnsafe:0x00020000`

Prevents the **Never ask me** check box from being enabled. Use of this flag means **FTA_OpenIsSafe** is not respected and [AssocIsDangerous](https://learn.microsoft.com/windows/desktop/api/shlwapi/nf-shlwapi-associsdangerous) always returns TRUE.
If your file type can execute code, you should always use this flag or ensure that the file type handlers mitigate risks, for example, by producing warning prompts before running the code.

The user can override this attribute through the **File Type** dialog box.

### `FTA_NoRecentDocs:0x00100000`

Prohibits the addition of members of this file type to the [Recent Documents](https://learn.microsoft.com/windows/desktop/shell/manage) folder. Additionally, in Windows 7 and later, prohibits the addition of members of this file type to the automatic **Recent** or **Frequent** category of an application's Jump List.

This flag does not restrict members of this file type from being added to a [custom Jump List](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-icustomdestinationlist). It also places no restriction on the file type being added to the automatic Jump Lists of other applications in the case that other applications use this file type.

### `FTA_SafeForElevation:0x00200000`

**Introduced in Windows 8**. Marks the file or URI scheme as safe to be used from a low trust application. Files that originate from the Internet or an app container are examples where the file is considered untrusted. Untrusted files that contain code are especially dangerous, and appropriate security mitigations must be applied if the file is to be opened by a full trust application. File type owners for file formats that have the ability to execute code should specify this flag only if their program mitigates elevation-of-privilege threats that are associated with running code at a higher integrity level. Mitigations include prompting the user before code is executed or executing the code with reduced privileges.

By specifying this flag for an entire file type, an app running within an app container can pass files of this type to a program running at full trust. Some file types are recognized as inherently dangerous due to their ability to execute code and will be blocked if you don't specify this value.

### `FTA_AlwaysUseDirectInvoke:0x00400000`

**Introduced in Windows 8**. Ensures that the verbs for the file type are invoked with a URI instead of a downloaded version of the file. Use this flag only if you've registered the file type's verb to support DirectInvoke through the SupportedProtocols or UseUrl registration.

## Remarks

These flags represent possible attributes stored in the EditFlags value of a ProgID registration. The EditFlags data is a single REG_DWORD.

The following example shows the **FTA_NoRemove** (0x00000010) and **FTA_NoNewVerb** (0x00000020) attributes assigned to the .myp file type.

```
HKEY_CLASSES_ROOT
   .myp
      (Default) = MyProgram.1
   MyProgram.1
      (Default) = MyProgram Application
      EditFlags = 0x00000030
```

\

APIs such as [IQueryAssociations::GetData](https://learn.microsoft.com/windows/desktop/api/shlwapi/nf-shlwapi-iqueryassociations-getdata) can retrieve that EditFlags data. Compare the numerical equivalents of these **FILETYPEATTRIBUTEFLAGS** flags against that retrieved value to determine which flags are set.

The following example demonstrates the use of [IQueryAssociations::GetData](https://learn.microsoft.com/windows/desktop/api/shlwapi/nf-shlwapi-iqueryassociations-getdata) to determine if those values are set.

```
IQueryAssociations *passoc;

HRESULT hr = AssocCreate(CLSID_QueryAssociations, IID_PPV_ARGS(&passoc));
if (SUCCEEDED(hr))
{
    hr = passoc->Init(NULL, pszType, NULL, NULL);
    if (SUCCEEDED(hr))
    {
        DWORD dwEditFlags;
        ULONG cb = sizeof(dwEditFlags);

        hr = passoc->GetData(NULL, ASSOCDATA_EDITFLAGS, NULL, &dwEditFlags, &cb);
        if (SUCCEEDED(hr))
        {
            if (dwEditFlags & 0x00000010) // FTA_NoRemove
            {
                // ...
            }
            if (dwEditFlags & 0x00000020)  // FTA_NoNewVerb
            {
                // ...
            }
        }
    }
    passoc->Release();
}
```

To set an EditFlags attribute, you can use the [RegSetValueEx](https://learn.microsoft.com/windows/desktop/api/winreg/nf-winreg-regsetvalueexa) or [SHSetValue](https://learn.microsoft.com/windows/desktop/api/shlwapi/nf-shlwapi-shsetvaluea) functions. First use [IQueryAssociations::GetData](https://learn.microsoft.com/windows/desktop/api/shlwapi/nf-shlwapi-iqueryassociations-getdata) to retrieve the current set of attributes as shown in the example above, add the desired **FILETYPEATTRIBUTEFLAGS** to that value, then write that value back to the registry using one of the two set functions.