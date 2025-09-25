# RegisterActiveObject function

## Description

Registers an object as the active object for its class.

## Parameters

### `punk`

The active object.

### `rclsid`

The CLSID of the active object.

### `dwFlags`

Flags controlling registration of the object. Possible values are ACTIVEOBJECT_STRONG and ACTIVEOBJECT_WEAK.

### `pdwRegister`

Receives a handle. This handle must be passed to [RevokeActiveObject](https://learn.microsoft.com/previous-versions/windows/desktop/api/oleauto/nf-oleauto-revokeactiveobject) to end the object's active status.

## Return value

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

The **RegisterActiveObject** function registers the object to which *punk* points as the active object for the class denoted by *rclsid*. Registration causes the object to be listed in the running object table (ROT) of OLE, a globally accessible lookup table that keeps track of objects that are currently running on the computer. (For more information about the running object table, see the *COM Programmer's Reference*.) The *dwFlags* parameter specifies the strength or weakness of the registration, which affects the way the object is shut down.

In general, ActiveX objects should behave in the following manner:

* If the object is visible, it should shut down only in response to an explicit user command (such as the **Exit** command on the **File** menu), or to the equivalent command from an ActiveX client (invoking the **Quit** or **Exit** method on the Application object).
* If the object is not visible, it should shut down only when the last external connection to it is gone.

Strong registration performs an **AddRef** on the object, incrementing the reference count of the object (and its associated stub) in the running object table. A strongly registered object must be explicitly revoked from the table with [RevokeActiveObject](https://learn.microsoft.com/previous-versions/windows/desktop/api/oleauto/nf-oleauto-revokeactiveobject). The default is strong registration (ACTIVEOBJECT_STRONG).

Weak registration keeps a pointer to the object in the running object table, but does not increment the reference count. Consequently, when the last external connection to a weakly registered object disappears, OLE releases the object's stub, and the object itself is no longer available.

To ensure the desired behavior, consider not only the default actions of OLE, but also the following:

* Even though code can create an invisible object, the object may become visible at some later time. Once the object is visible, it should remain visible and active until it receives an explicit command to shut down. This can occur after references from the code disappear.
* Other ActiveX clients may be using the object. If so, the code should not force the object to shut down.

To avoid possible conflicts, you should always register ActiveX objects with ACTIVEOBJECT_WEAK, and call **CoLockObjectExternal**, when necessary, to guarantee the object remains active. **CoLockObjectExternal** adds a strong lock, thereby preventing the object's reference count from reaching zero. For detailed information about this function, refer to the *COM Programmer's Reference*.

Most commonly, objects need to call **CoLockObjectExternal** when they become visible, so they remain active until the user requests the object to shut down. The following procedure lists the steps your code should follow to shut down an object correctly.

**To shut down an active object:**

1. When the object becomes visible, make the following call to add a lock for user:

   ```cpp
   CoLockObjectExternal(punk, TRUE, TRUE)
   ```

   The lock remains in effect until a user explicitly requests the object to be shut down, such as with a **Quit** or **Exit** command.
2. When the user requests the object to be shut down, call **CoLockObjectExternal** again to free the lock, as follows:

   ```cpp
   CoLockObjectExternal(punk, FALSE, TRUE)
   ```
3. Call **RevokeActiveObject** to make the object inactive.
4. To end all connections from remote processes, call **CoDisconnectObject** as follows:

   ```cpp
   CoDisconnectObject(punk,0)
   ```

   This function is described in more detail in the *COM Programmer's Reference*.

## See also

[Registering the Active Object with API Functions](https://learn.microsoft.com/previous-versions/windows/desktop/automat/registration-functions)

[RevokeActiveObject](https://learn.microsoft.com/previous-versions/windows/desktop/api/oleauto/nf-oleauto-revokeactiveobject)