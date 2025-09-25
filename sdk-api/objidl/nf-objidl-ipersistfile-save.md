# IPersistFile::Save

## Description

Saves a copy of the object to the specified file.

## Parameters

### `pszFileName` [in]

The absolute path of the file to which the object should be saved. If *pszFileName* is **NULL**, the object should save its data to the current file, if there is one.

### `fRemember` [in]

Indicates whether the *pszFileName* parameter is to be used as the current working file. If **TRUE**, *pszFileName* becomes the current file and the object should clear its dirty flag after the save. If **FALSE**, this save operation is a **Save A Copy As ...** operation. In this case, the current file is unchanged and the object should not clear its dirty flag. If *pszFileName* is **NULL**, the implementation should ignore the *fRemember* flag.

## Return value

If the object was successfully saved, the return value is S_OK. Otherwise, it is S_FALSE. This method can also return various storage errors.

## Remarks

This method can be called to save an object to the specified file in one of three ways:

The implementer must detect which type of save operation the caller is requesting. If the *pszFileName* parameter is **NULL**, a **Save** is being requested. If the *pszFileName* parameter is not **NULL**, use the value of the *fRemember* parameter to distinguish between a **Save As** and a **Save a Copy As**.

In **Save** or **Save As** operations, **IPersistFile::Save** clears the internal dirty flag after the save and sends [IAdviseSink::OnSave](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-iadvisesink-onsave) notifications to any advisory connections (see also [IOleAdviseHolder::SendOnSave](https://learn.microsoft.com/windows/desktop/api/oleidl/nf-oleidl-ioleadviseholder-sendonsave)). Also, in these operations, the object is in NoScribble mode until it receives an [IPersistFile::SaveCompleted](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-ipersistfile-savecompleted) call. In NoScribble mode, the object must not write to the file.

In the **Save As** scenario, the implementation should also send [IAdviseSink::OnRename](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-iadvisesink-onrename) notifications to any advisory connections (see also [IOleAdviseHolder::SendOnRename](https://learn.microsoft.com/windows/desktop/api/oleidl/nf-oleidl-ioleadviseholder-sendonrename)).

In the **Save a Copy As** scenario, the implementation does not clear the internal dirty flag after the save.

### Notes to Callers

OLE does not call **IPersistFile::Save**. Typically, applications would not call it unless they are saving an object to a file directly, which is generally left to the end-user.

## See also

[IPersistFile](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-ipersistfile)