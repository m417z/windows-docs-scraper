# HidP_TranslateUsagesToI8042ScanCodes function

## Description

The **HidP_TranslateUsagesToI8042ScanCodes** routine maps a list of [HID usages](https://learn.microsoft.com/windows-hardware/drivers/hid/hid-usages) on the HID_USAGE_PAGE_KEYBOARD usage page to their respective PS/2 scan codes (Scan Code Set 1).

## Parameters

### `ChangedUsageList` [in]

Pointer to a list of keyboard (button) usages. The translate usages routine interprets a zero as a delimiter that ends the usage list.

### `UsageListLength` [in]

Specifies the maximum possible number of usages in the changed usage list.

### `KeyAction` [in]

Identifies the key direction for the specified change usage list.

```
typedef enum _HIDP_KEYBOARD_DIRECTION {
    HidP_Keyboard_Break,
    HidP_Keyboard_Make
} HIDP_KEYBOARD_DIRECTION;
```

#### HidP_Keyboard_Break

Specifies a *break* direction (key up). The changed usage list contains the usages set to OFF that were previously set to ON (which corresponds to the keys that were previously down, but are now up).

#### HidPKeyboard_Make

Specifies a *make* direction (key down). The changed usage list contains the usages set to ON that were previously set to OFF (which corresponds to the keys that were previously up, but now are down).

### `ModifierState` [in, out]

Pointer to a _HIDP_KEYBOARD_MODIFIER_STATE structure that the caller maintains for use by the translate usages routine. The modifier state structure identifies the state of the keyboard modifier keys.

```
typedef struct _HIDP_KEYBOARD_MODIFIER_STATE {
    union {
      struct {
        ULONG LeftControl: 1;
        ULONG LeftShift: 1;
        ULONG LeftAlt: 1;
        ULONG LeftGUI: 1;
        ULONG RightControl: 1;
        ULONG RightShift: 1;
        ULONG RightAlt: 1;
        ULONG RigthGUI: 1;
        ULONG CapsLock: 1;
        ULONG ScollLock: 1;
        ULONG NumLock: 1;
        ULONG Reserved: 21;
      };
      ULONG ul;
};
```

Each member of the modifier state structure identifies whether the corresponding usage is set to ON (1) or OFF (zero).

See the Remarks section for more information about how a modifier state structure is used with the translate usage routine.

### `InsertCodesProcedure` [in]

Pointer to a caller-supplied PHIDP_INSERT_SCANCODES-typed callback routine that the translate usage routine uses to return the mapped scan codes to the caller of the translate usage routine.

```
typedef BOOLEAN (*PHIDP_INSERT_SCANCODES)(
    IN PVOID  Context,
    IN PCHAR  NewScanCodes,
    IN ULONG  Length
    );
```

#### Context

Pointer to the context of the caller of the translate usage routine. The translate usage routine passes the *InsertCodesContext* pointer to the *InsertCodesProcedure* routine.

#### NewScanCodes

Pointer to the first byte of a scan code that the translate usage routine returns to the caller of the translate usage routine.

#### Length

Specifies the length, in bytes, of the scan code. A scan code cannot exceed four bytes.

### `InsertCodesContext` [in, optional]

Pointer to a caller-defined context that the translate usage routine passes to the *InsertCodesProcedure* routine.

## Return value

**HidP_TranslateUsagesToI8042ScanCodes** returns one of the following status values:

| Return code | Description |
| --- | --- |
| **HIDP_STATUS_SUCCESS** | The translate usage routine successfully mapped all the valid usages in the changed usage list. |
| **HIDP_STATUS_I8042_TRANS_UNKNOWN** | A usage in the changed usage list mapped to an invalid keyboard scan code. |

## Remarks

**HidP_TranslateUsagesToI8042ScanCodes** sequentially maps the keyboard button usages in the changed usage list in the order in which they occur in the list, beginning with the value at *ChangedUsageList.* After the translate usage routine successfully maps a usage, it uses the caller's *InsertCodesProcedure* routine to return the corresponding scan code to the caller. The translate usage routine continues to map the usages in the list until one of the following occurs: a usage value in the list is zero; it maps the number of usages that is specified by *UsageListLength*; a usage maps to an invalid keyboard scan code.

**HidP_TranslateUsagesToI8042ScanCodes** is designed primarily to be used in a processing loop that repeatedly determines the current usage list (usages that are currently set to ON), compares them with a previous usage list (usages that were previously set to ON), and maps the difference between the current and previous usage lists to make scan codes and break scan codes. The following operations illustrate how to use the translate usages routine.

Prior to beginning a processing loop, the processing code typically allocates and initializes the following data:

* A previous usage list, current usage list, break usage list, and a make usage list.

  Each list is a zero-initialized array of usages. To ensure that the processing code maps all the usages that can change between consecutive HID input reports, the processing code must set the number of elements in each list to the maximum number of usages that [HidP_GetUsages](https://learn.microsoft.com/windows-hardware/drivers/ddi/hidpi/nf-hidpi-hidp_getusages) can return for the HID_USAGE_PAGE_KEYBOARD usage page. This number is obtained using [HidP_MaxUsageListLength](https://learn.microsoft.com/windows-hardware/drivers/ddi/hidpi/nf-hidpi-hidp_maxusagelistlength).
* A zero-initialized _HIDP_KEYBOARD_MODIFIER_STATE structure for use by the translate usages routine.

  In the processing loop, the code must maintain this structure for use by the translate usages routine. The processing code can read the state of the modifier keys, but the code must not modify the structure. The translate usage routine uses this structure to maintain internal information about the state of the modifier keys.

After initializing the required structures, each iteration of the processing loop typically includes the following sequence of operations:

1. Call **HidP_GetUsages** to obtain the current usage list of usages that are set to ON. Set the *UsagePage* input parameter of the get usages routine to HID_USAGE_PAGE_KEYBOARD.
2. Call **HidP_UsageListDifference** to compare the current usage list of usages to a previous usage list. The usage list difference routine returns a break usage list and a make usage list.
3. Call the translate usage routine, setting *ChangedUsageList* to the break usage list, *KeyAction* to HidP_KeyboardBreak, and *ModifierState* to the structure that the processing code maintains for the translate usages routine. The translate usages routine uses the *InsertCodesProcedure*s callback routine to return the break scan codes to the processing loop.
4. Call the translate usage routine, setting *ChangedUsageList* to the make usage list, *KeyAction* to HidP_KeyboardMake, and *ModifierState* to the structure that the processing code maintains for the translate usages routine. The translate usages routine uses the *InsertCodesProcedure*s callback routine to return the make scan codes to the processing loop.
5. Update the previous usage list to the current usage list.

For information about the mapping between HID usages and PS/2 keyboard scan codes, see the [key support and scan codes](https://go.microsoft.com/fwlink/p/?linkid=242210) website.

## See also

[HidP_GetUsages](https://learn.microsoft.com/windows-hardware/drivers/ddi/hidpi/nf-hidpi-hidp_getusages)

[HidP_MaxUsageListLength](https://learn.microsoft.com/windows-hardware/drivers/ddi/hidpi/nf-hidpi-hidp_maxusagelistlength)

[HidP_UsageListDifference](https://learn.microsoft.com/windows-hardware/drivers/ddi/hidpi/nf-hidpi-hidp_usagelistdifference)