# ShellCommandInfo structure

## Description

The **ShellCommandInfo** structure contains data required to launch an additional application for manual repair options.

## Members

### `pwszOperation`

Type: **[string] LPWSTR**

A pointer to a null-terminated string that contains the action to be performed. The set of available verbs that specifies the action depends on the particular file or folder. Generally, the actions available from an object's shortcut menu are available verbs. For more information, see the Remarks section.

### `pwszFile`

Type: **[string] LPWSTR**

A pointer to a null-terminated string that specifies the file or object on which to execute the specified verb. To specify a Shell namespace object, pass the fully qualified parse name. Note that not all verbs are supported on all objects. For example, not all document types support the "print" verb.

### `pwszParameters`

Type: **[string] LPWSTR**

A pointer to a null-terminated strings that specifies the parameters to be passed to the application, only if the *pwszFile* parameter specifies an executable file. The format of this string is determined by the verb that is to be invoked. If *pwszFile* specifies a document file, *pwszParameters* should be **NULL**.

### `pwszDirectory`

Type: **[string] LPWSTR**

A pointer to a null-terminated string that specifies the default directory.

### `nShowCmd`

Type: **ULONG**

Flags that specify how an application is to be displayed when it is opened. If *pwszFile* specifies a document file, the flag is simply passed to the associated application. It is up to the application to decide how to handle it.

## Remarks

In the case of a manual repair option, the caller can use this structure to call the ShellExecute function to launch an additional application that can help the user to repair the problem.

The following verbs are used in connection with *pwszOperation*.

| Term | Description |
| --- | --- |
| edit | Launches an editor and opens the document for editing. If *pwszFile* is not a document file, the function fails. |
| explore | Explores the folder specified by the *pwszFile* parameter. |
| find | Initiates a search starting from the specified directory. |
| open | Opens the file specified by the *pwszFile* parameter. The file can be an executable file, a document file, or a folder. |
| print | Prints the document file specified by the *pwszFile* parameter. If *pwszFile* is not a document file, the function fails. |
| NULL | Used when other verbs do not apply. |