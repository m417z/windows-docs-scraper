# CM_Get_HW_Prof_Flags_ExA function

## Description

[This function has been deprecated and should not be used.]

The **CM_Get_HW_Prof_Flags_Ex** function retrieves the [hardware profile](https://learn.microsoft.com/windows-hardware/drivers/)-specific configuration flags for a [device instance](https://learn.microsoft.com/windows-hardware/drivers/) on a remote machine or a local machine.

## Parameters

### `pDeviceID` [in]

Pointer to a NULL-terminated string that contains the device instance ID of the device for which to retrieve hardware profile-specific configuration flags.

### `ulHardwareProfile` [in]

A variable of ULONG type that specifies the identifier of the hardware profile for which to retrieve configuration flags. If this parameter is zero, this function retrieves the configuration flags for the current hardware profile.

### `pulValue` [out]

Pointer to a caller-supplied variable of ULONG type that receives zero or a bitwise OR of the following configuration flags that are defined in *Regstr.h*:

#### CSCONFIGFLAG_BITS

Bitwise OR of the other CSCONFIGFLAG_Xxx flags.

#### CSCONFIGFLAG_DISABLE

The device instance is disabled in the specified hardware profile.

#### CSCONFIGFLAG_DO_NOT_CREATE

The hardware profile does not support the specified device instance.

#### CSCONFIGFLAG_DO_NOT_START

The device cannot be started in the specified hardware profile.

### `ulFlags` [in]

Reserved for internal use. Must be set to zero.

### `hMachine` [in, optional]

A machine handle that is returned by call to [CM_Connect_Machine](https://learn.microsoft.com/windows/desktop/api/cfgmgr32/nf-cfgmgr32-cm_connect_machinew) or **NULL**. If this parameter is set to **NULL**, **CM_Get_HW_Prof_Flags_Ex** retrieves the configuration flags on the local machine.

**Note** Using this function to access remote machines is not supported beginning with Windows 8 and Windows Server 2012, as this functionality has been removed.

## Return value

If the operation succeeds, **CM_Get_HW_Prof_Flags** returns CR_SUCCESS. Otherwise, the function returns one of the CR_-prefixed error codes that are defined in *Cfgmgr32.h*.

## Remarks

To retrieve a list of the hardware profile IDs that are currently defined on a remote machine, call [SetupDiGetHwProfileListEx](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupdigethwprofilelistexa).

 Functionality to access remote machines has been removed in Windows 8 and Windows Server 2012 and later operating systems thus you cannot access remote machines when running on these versions of Windows.

> [!NOTE]
> The cfgmgr32.h header defines CM_Get_HW_Prof_Flags_Ex as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[CM_Get_HW_Prof_Flags](https://learn.microsoft.com/windows/desktop/api/cfgmgr32/nf-cfgmgr32-cm_get_hw_prof_flagsa)

[SetupDiGetHwProfileFriendlyNameEx](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupdigethwprofilefriendlynameexa)

[SetupDiGetHwProfileListEx](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupdigethwprofilelistexa)