# IPersistFile::SaveCompleted

## Description

Notifies the object that it can write to its file. It does this by notifying the object that it can revert from NoScribble mode (in which it must not write to its file), to Normal mode (in which it can). The component enters NoScribble mode when it receives an [IPersistFile::Save](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-ipersistfile-save) call.

## Parameters

### `pszFileName` [in]

The absolute path of the file where the object was saved previously.

## Return value

This method always returns S_OK.

## Remarks

**SaveCompleted** is called when a call to [IPersistFile::Save](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-ipersistfile-save) is completed, and the file that was saved is now the current working file (having been saved with **Save** or **Save As** operations). The call to **Save** puts the object into NoScribble mode so it cannot write to its file. When **SaveCompleted** is called, the object reverts to Normal mode, in which it is free to write to its file.

### Notes to Callers

OLE does not call the **SaveCompleted** method. Typically, applications would not call it unless they are saving objects directly to files, an operation which is generally left to the end-user.

## See also

[IPersistFile](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-ipersistfile)