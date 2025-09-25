# CM_Enumerate_Classes_Ex function

## Description

[Beginning with Windows 8 and Windows Server 2012, this function has been deprecated. Please use [CM_Enumerate_Classes](https://learn.microsoft.com/windows/desktop/api/cfgmgr32/nf-cfgmgr32-cm_enumerate_classes) instead.]

The **CM_Enumerate_Classes_Ex** function, when called repeatedly, enumerates a local or a remote machine's installed [device classes](https://learn.microsoft.com/windows-hardware/drivers/install/overview-of-device-setup-classes), by supplying each class's GUID.

## Parameters

### `ulClassIndex` [in]

Caller-supplied index into the machine's list of device classes. For more information, see the following **Remarks** section.

### `ClassGuid` [out]

Caller-supplied address of a GUID structure (described in the Microsoft Windows SDK) to receive a device class's GUID.

### `ulFlags` [in]

Beginning with Windows 8, callers can specify the following flags:

#### CM_ENUMERATE_CLASSES_INSTALLER

Enumerate device setup classes.

#### CM_ENUMERATE_CLASSES_INTERFACE

Enumerate device interface classes.

Otherwise, should be set to zero.

### `hMachine` [in, optional]

Caller-supplied machine handle, obtained from a previous call to [CM_Connect_Machine](https://learn.microsoft.com/windows/desktop/api/cfgmgr32/nf-cfgmgr32-cm_connect_machinew).

**Note** Using this function to access remote machines is not supported beginning with Windows 8 and Windows Server 2012, as this functionality has been removed.

## Return value

If the operation succeeds, the function returns CR_SUCCESS. Otherwise, it returns one of the CR_-prefixed error codes defined in *Cfgmgr32.h*.

## Remarks

To enumerate the local or a remote machine's device classes, call **CM_Enumerate_Classes_Ex** repeatedly, starting with a *ulClassIndex* index value of zero and incrementing the index value with each subsequent call until the function returns CR_NO_SUCH_VALUE. Some index values might represent list entries containing invalid class data, in which case the function returns CR_INVALID_DATA. This return value can be ignored.

The class GUIDs obtained from this function can be used as input to the [device installation functions](https://learn.microsoft.com/windows-hardware/drivers/install/using-device-installation-functions#ddk-update-driver-function-dg).

Beginning with Windows 8 and later operating systems, callers can use the **ulFlags** member to specify which device classes CM_Enumerate_Classes_Ex should return. Prior to Windows 8, CM_Enumerate_Classes_Ex returned only device setup classes.

 Functionality to access remote machines has been removed in Windows 8 and Windows Server 2012 and later operating systems thus you cannot access remote machines when running on these versions of Windows.

## See also

[CM_Enumerate_Classes](https://learn.microsoft.com/windows/desktop/api/cfgmgr32/nf-cfgmgr32-cm_enumerate_classes)