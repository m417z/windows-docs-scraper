# IOleObject::SetHostNames

## Description

Provides an object with the names of its container application and the compound document in which it is embedded.

## Parameters

### `szContainerApp` [in]

Pointer to the name of the container application in which the object is running.

### `szContainerObj` [in]

Pointer to the name of the compound document that contains the object. If you do not wish to display the name of the compound document, you can set this parameter to **NULL**.

## Return value

This method returns S_OK on success.

## Remarks

### Notes for Callers

Call **IOleObject::SetHostNames** only for embedded objects, because for linked objects, the link source provides its own separate editing window and title bar information.

### Notes to Implementers

An object's application of **IOleObject::SetHostNames** should include whatever modifications to its user interface may be appropriate to an object's embedded state. Such modifications typically will include adding and removing menu commands and altering the text displayed in the title bar of the editing window.

The complete window title for an embedded object in an SDI container application or an MDI application with a maximized child window should appear as follows:

``` syntax
<object application name> - <object short type> in <container document>
```

Otherwise, the title should be:

``` syntax
<object application name> - <container document>
```

The "object short type" refers to a form of an object's name short enough to be displayed in full in a list box. Because these identifying strings are not stored as part of the persistent state of the object, **IOleObject::SetHostNames** must be called each time the object loads or runs.

## See also

[IOleObject](https://learn.microsoft.com/windows/desktop/api/oleidl/nn-oleidl-ioleobject)

[IOleObject::GetUserType](https://learn.microsoft.com/windows/desktop/api/oleidl/nf-oleidl-ioleobject-getusertype)