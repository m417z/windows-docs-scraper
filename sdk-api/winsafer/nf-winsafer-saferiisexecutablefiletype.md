# SaferiIsExecutableFileType function

## Description

The **SaferiIsExecutableFileType** function determines whether a specified file is an executable file. Applications use this function to determine whether a file is an executable file, and if it is, then the application can take security precautions to prevent invoking untrustworthy code.

## Parameters

### `szFullPathname` [in]

Pointer to a **null**-terminated [Unicode](https://learn.microsoft.com/windows/desktop/SecGloss/u-gly) character string for the name of the file. The path is optional because only the file name extension is evaluated. The evaluation of the file name extension is not case-sensitive. This parameter cannot be **NULL** or an empty string, and the specified file must include a file name extension.

### `bFromShellExecute` [in]

Boolean value that determines whether .exe files are treated as executable files for the file type evaluation. Set this value to **TRUE** to omit .exe files from the evaluation or to **FALSE** to include them.

## Return value

If the function successfully recognizes the file name's extension as an executable file type, the return value is **TRUE**.

If the function fails, or if *szFullPath* identifies a file name with a nonexecutable extension, the function returns **FALSE**.

## Remarks

The following file name extensions are examples of executable file types. This is not a complete list.

* .bat
* .cmd
* .com
* .exe
* .js
* .lnk
* .pif
* .pl
* .shs
* .url
* .vbs

The security policy Microsoft Management Console (MMC) snap-in (Secpol.msc) controls which extensions are considered executable file types.

**To view or modify the extensions that are considered executable file types**

1. Run Secpol.msc.
2. Expand **Software Restriction Policies**, and then double-click **Designated File Types**.

**Note** To view the **Designated File Types** property page, you may need to create the **Software Restriction Policies** node. To create the **Software Restriction Policies** node, follow the instructions that appear when you expand **Software Restriction Policies**.