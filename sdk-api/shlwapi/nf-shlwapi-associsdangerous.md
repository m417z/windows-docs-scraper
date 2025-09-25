# AssocIsDangerous function

## Description

Determines whether a file type is considered a potential security risk.

## Parameters

### `pszAssoc` [in]

Type: **PCWSTR**

A pointer to a string that contains the type of file in question. This may be either an extension such as ".exe" or a progid such as "exefile".

## Return value

Type: **BOOL**

Returns **TRUE** if the file type is considered dangerous; otherwise, **FALSE**.

## Remarks

Files that are determined to be potentially dangerous, such as .exe files, should be handled with more care than other files. For example, Windows Internet Explorer version 6.01 or later uses **AssocIsDangerous** to determine whether it should issue stronger warning language in its download dialog box. [ShellExecuteEx](https://learn.microsoft.com/windows/desktop/api/shellapi/nf-shellapi-shellexecuteexa) uses **AssocIsDangerous** to trigger zone checking using the methods of the [IInternetSecurityManager](https://learn.microsoft.com/previous-versions/windows/internet-explorer/ie-developer/platform-apis/ms537130(v=vs.85)) interface in conjunction with the [URLACTION_SHELL_SHELLEXECUTE](https://learn.microsoft.com/previous-versions/windows/internet-explorer/ie-developer/platform-apis/ms537178(v=vs.85)) flag.

The determination of a file's potential risk is made by checking its type against several sources, including a list of known dangerous types and the presence of the FTA_AlwaysUnsafe flag in the registry. On systems running Windows XPService Pack 1 (SP1) or later or Windows Server 2003, it also uses the [SaferiIsExecutableFileType](https://learn.microsoft.com/windows/desktop/api/winsafer/nf-winsafer-saferiisexecutablefiletype) function to determine whether a file type is executable.

Applications that can take advantage of **AssocIsDangerous** include email programs, browsers, chat clients capable of downloading files, and any application that moves files or data from one zone of trust to another.

## See also

[File Types](https://learn.microsoft.com/windows/desktop/shell/fa-file-types)

[SaferiIsExecutableFileType](https://learn.microsoft.com/windows/desktop/api/winsafer/nf-winsafer-saferiisexecutablefiletype)