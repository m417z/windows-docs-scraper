# EX_CALLBACK_FUNCTION callback function

## Description

A filter driver's *RegistryCallback* routine can monitor, block, or modify a registry operation.

## Parameters

### `CallbackContext` [in]

The value that the driver passed as the *Context* parameter to [CmRegisterCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-cmregistercallback) or [CmRegisterCallbackEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-cmregistercallbackex) when it registered this *RegistryCallback* routine.

### `Argument1` [in, optional]

A [**REG_NOTIFY_CLASS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ne-wdm-_reg_notify_class)-typed value that identifies the type of registry operation that is being performed and whether the *RegistryCallback* routine is being called before or after the registry operation is performed.

### `Argument2` [in, optional]

A pointer to a structure that contains information that is specific to the type of registry operation. The structure type depends on the [**REG_NOTIFY_CLASS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ne-wdm-_reg_notify_class)-typed value for *Argument1*, as shown in the following table. For information about which REG_NOTIFY_CLASS-typed values are available for which operating system versions, see [**REG_NOTIFY_CLASS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ne-wdm-_reg_notify_class).

| REG_NOTIFY_CLASS value | Structure type |
|--|--|
| **RegNtDeleteKey** | [REG_DELETE_KEY_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_reg_delete_key_information) |
| **RegNtPreDeleteKey** | [REG_DELETE_KEY_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_reg_delete_key_information) |
| **RegNtPostDeleteKey** | [REG_POST_OPERATION_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_reg_post_operation_information) |
| **RegNtSetValueKey** | [REG_SET_VALUE_KEY_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_reg_set_value_key_information) |
| **RegNtPreSetValueKey** | [REG_SET_VALUE_KEY_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_reg_set_value_key_information) |
| **RegNtPostSetValueKey** | [REG_POST_OPERATION_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_reg_post_operation_information) |
| **RegNtDeleteValueKey** | [REG_DELETE_VALUE_KEY_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_reg_delete_value_key_information) |
| **RegNtPreDeleteValueKey** | [REG_DELETE_VALUE_KEY_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_reg_delete_value_key_information) |
| **RegNtPostDeleteValueKey** | [REG_POST_OPERATION_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_reg_post_operation_information) |
| **RegNtSetInformationKey** | [REG_SET_INFORMATION_KEY_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_reg_set_information_key_information) |
| **RegNtPreSetInformationKey** | [REG_SET_INFORMATION_KEY_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_reg_set_information_key_information) |
| **RegNtPostSetInformationKey** | [REG_POST_OPERATION_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_reg_post_operation_information) |
| **RegNtRenameKey** | [REG_RENAME_KEY_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_reg_rename_key_information) |
| **RegNtPreRenameKey** | [REG_RENAME_KEY_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_reg_rename_key_information) |
| **RegNtPostRenameKey** | [REG_POST_OPERATION_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_reg_post_operation_information) |
| **RegNtEnumerateKey** | [REG_ENUMERATE_KEY_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_reg_enumerate_key_information) |
| **RegNtPreEnumerateKey** | [REG_ENUMERATE_KEY_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_reg_enumerate_key_information) |
| **RegNtPostEnumerateKey** | [REG_POST_OPERATION_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_reg_post_operation_information) |
| **RegNtEnumerateValueKey** | [REG_ENUMERATE_VALUE_KEY_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_reg_enumerate_value_key_information) |
| **RegNtPreEnumerateValueKey** | [REG_ENUMERATE_VALUE_KEY_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_reg_enumerate_value_key_information) |
| **RegNtPostEnumerateValueKey** | [REG_POST_OPERATION_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_reg_post_operation_information) |
| **RegNtQueryKey** | [REG_QUERY_KEY_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_reg_query_key_information) |
| **RegNtPreQueryKey** | [REG_QUERY_KEY_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_reg_query_key_information) |
| **RegNtPostQueryKey** | [REG_POST_OPERATION_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_reg_post_operation_information) |
| **RegNtQueryValueKey** | [REG_QUERY_VALUE_KEY_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_reg_query_value_key_information) |
| **RegNtPreQueryValueKey** | [REG_QUERY_VALUE_KEY_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_reg_query_value_key_information) |
| **RegNtPostQueryValueKey** | [REG_POST_OPERATION_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_reg_post_operation_information) |
| **RegNtQueryMultipleValueKey** | [REG_QUERY_MULTIPLE_VALUE_KEY_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_reg_query_multiple_value_key_information) |
| **RegNtPreQueryMultipleValueKey** | [REG_QUERY_MULTIPLE_VALUE_KEY_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_reg_query_multiple_value_key_information) |
| **RegNtPostQueryMultipleValueKey** | [REG_POST_OPERATION_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_reg_post_operation_information) |
| **RegNtPreCreateKey** | [REG_PRE_CREATE_KEY_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_reg_pre_create_key_information) |
| **RegNtPreCreateKeyEx** | [REG_CREATE_KEY_INFORMATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_reg_create_key_information) |
| **RegNtPostCreateKey** | [REG_POST_CREATE_KEY_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_reg_post_create_key_information) |
| **RegNtPostCreateKeyEx** | [REG_POST_OPERATION_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_reg_post_operation_information) |
| **RegNtPreOpenKey** | [REG_PRE_OPEN_KEY_INFORMATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_reg_pre_create_key_information) |
| **RegNtPreOpenKeyEx** | [REG_OPEN_KEY_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_reg_create_key_information) |
| **RegNtPostOpenKey** | [REG_POST_OPEN_KEY_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_reg_post_create_key_information) |
| **RegNtPostOpenKeyEx** | [REG_POST_OPERATION_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_reg_post_operation_information) |
| **RegNtKeyHandleClose** | [REG_KEY_HANDLE_CLOSE_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_reg_key_handle_close_information) |
| **RegNtPreKeyHandleClose** | [REG_KEY_HANDLE_CLOSE_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_reg_key_handle_close_information) |
| **RegNtPostKeyHandleClose** | [REG_POST_OPERATION_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_reg_post_operation_information) |
| **RegNtPreFlushKey** | [REG_FLUSH_KEY_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_reg_delete_key_information) |
| **RegNtPostFlushKey** | [REG_POST_OPERATION_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_reg_post_operation_information) |
| **RegNtPreLoadKey** | [REG_LOAD_KEY_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_reg_load_key_information) |
| **RegNtPostLoadKey** | [REG_POST_OPERATION_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_reg_post_operation_information) |
| **RegNtPreUnLoadKey** | [REG_UNLOAD_KEY_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_reg_unload_key_information) |
| **RegNtPostUnLoadKey** | [REG_POST_OPERATION_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_reg_post_operation_information) |
| **RegNtPreQueryKeySecurity** | [REG_QUERY_KEY_SECURITY_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_reg_query_key_security_information) |
| **RegNtPostQueryKeySecurity** | [REG_POST_OPERATION_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_reg_post_operation_information) |
| **RegNtPreSetKeySecurity** | [REG_SET_KEY_SECURITY_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_reg_set_key_security_information) |
| **RegNtPostSetKeySecurity** | [REG_POST_OPERATION_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_reg_post_operation_information) |
| **RegNtCallbackObjectContextCleanup** | [REG_CALLBACK_CONTEXT_CLEANUP_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_reg_callback_context_cleanup_information) |
| **RegNtPreRestoreKey** | [REG_RESTORE_KEY_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_reg_restore_key_information) |
| **RegNtPostRestoreKey** | [REG_POST_OPERATION_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_reg_post_operation_information) |
| **RegNtPreSaveKey** | [REG_SAVE_KEY_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_reg_save_key_information) |
| **RegNtPostSaveKey** | [REG_POST_OPERATION_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_reg_post_operation_information) |
| **RegNtPreReplaceKey** | [REG_REPLACE_KEY_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_reg_replace_key_information) |
| **RegNtPostReplaceKey** | [REG_POST_OPERATION_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_reg_post_operation_information) |
| **RegNtPreQueryKeyName** | [REG_QUERY_KEY_NAME](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_reg_query_key_name) |
| **RegNtPostQueryKeyName** | [REG_POST_OPERATION_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_reg_post_operation_information) |
| **RegNtPreSaveMergedKey** | [REG_SAVE_MERGED_KEY_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-reg_save_merged_key_information) |
| **RegNtPostSaveMergedKey** | [REG_POST_OPERATION_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_reg_post_operation_information) |

Starting with Windows 7, the actual data structure passed in when the notify class is RegNtPreCreateKeyEx or RegNtPreOpenKeyEx is the V1 version of this structure, [**REG_CREATE_KEY_INFORMATION_V1**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_reg_create_key_information_v1) or **REG_OPEN_KEY_INFORMATION_V1**, respectively. Check the Reserved member to determine the version of the structure.

| Version number | Structure name |
|--|--|
| 0 | REG_CREATE_KEY_INFORMATION and REG_OPEN_KEY_INFORMATION |
| 1 | REG_CREATE_KEY_INFORMATION_V1 and REG_OPEN_KEY_INFORMATION_V1 |

## Return value

For more information about when a *RegistryCallback* routine should return each of these status values, see [Filtering Registry Calls](https://learn.microsoft.com/windows-hardware/drivers/kernel/filtering-registry-calls).

## Remarks

To be notified of registry operations, a kernel-mode component (such as the driver component of an antivirus software package) can call [CmRegisterCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-cmregistercallback) or [CmRegisterCallbackEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-cmregistercallbackex) to register a *RegistryCallback* routine.

The *RegistryCallback* routine can inspect the contents of the input and output buffers that are supplied for registry operations. A registry operation can be initiated by a user-mode application that calls a user-mode registry routine (such as [RegCreateKeyEx](https://learn.microsoft.com/windows/win32/api/winreg/nf-winreg-regcreatekeyexa) or [RegOpenKeyEx](https://learn.microsoft.com/windows/win32/api/winreg/nf-winreg-regopenkeyexa)) or by a driver that calls a kernel-mode registry routine (such as [ZwCreateKey](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-zwcreatekey) or [ZwOpenKey](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-zwopenkey)). An *input buffer* is a memory buffer supplied by the initiator from which the registry reads input data for the operation. An *output buffer* is a buffer supplied by the initiator into which the registry writes output data requested by the initiator.

Before calling the *RegistryCallback* routine, the kernel probes (to verify alignment and accessibility) all members of the *Argument2* structures that point to output buffers in user-mode memory, but does not capture user-mode output buffers in system memory. The callback routine must enclose any access of an output buffer in a **try**/**except** block. If the callback routine needs to pass an output buffer pointer to a system routine (for example, [ZwOpenKey](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-zwopenkey)), and the buffer is in user-mode memory, the callback routine must first capture the buffer.

The handling of input buffers depends on the Windows version. Starting with Windows 8, the kernel captures all input buffers pointed to by members of the *Argument2* structures in system memory before calling the *RegistryCallback* routine. In versions of Windows before Windows 8, the kernel probes all members of the *Argument2* structures that point to input buffers in user-mode memory, but captures only some of these buffers in system memory. In these earlier versions of Windows, the callback routine must enclose any access of an input buffer in a **try**/**except** block. Additionally, if the callback routine needs to pass an input buffer pointer to a system routine (for example, **ZwOpenKey**), and the buffer is in user-mode memory, the callback routine must first capture the buffer.

The following table summarizes the requirements for buffer accesses by the *RegistryCallback* routine.

| Buffer type | Windows version | Buffer pointer passed to callback routine | Safe for callback routine to directly access? | Safe to pass to system routines (such as **ZwOpenKey**)? |
|--|--|--|--|--|
| User-mode input | Windows 8 and later | Points to captured data. | Yes | Yes |
| User-mode input | Windows 7 and earlier | Points to captured data or original user-mode buffer. | No. Must read under try/except. | No. Must allocate kernel memory, copy data from the original buffer under try/except, and pass the copied data to the system routine. |
| User-mode output | All | Points to original user-mode buffer. | No. Must write under try/except. | No. Must allocate kernel memory, pass kernel memory to the system routine, and copy the results back to the original buffer under try/except. |
| Kernel-mode input and output | All | Points to original kernel-mode buffer. | Yes | Yes |

For more information about *RegistryCallback* routines and registry filter drivers, see [Filtering Registry Calls](https://learn.microsoft.com/windows-hardware/drivers/kernel/filtering-registry-calls).

A *RegistryCallback* executes at IRQL = PASSIVE_LEVEL and in the context of the thread that is performing the registry operation.

### Examples

To define a *RegistryCallback* callback routine, you must first provide a function declaration that identifies the type of callback routine you're defining. Windows provides a set of callback function types for drivers. Declaring a function using the callback function types helps [Code Analysis for Drivers](https://learn.microsoft.com/windows-hardware/drivers/devtest/code-analysis-for-drivers), [Static Driver Verifier](https://learn.microsoft.com/windows-hardware/drivers/devtest/static-driver-verifier) (SDV), and other verification tools find errors, and it's a requirement for writing drivers for the Windows operating system.

For example, to define a *RegistryCallback* callback routine that is named `MyRegistryCallback`, use the EX_CALLBACK_FUNCTION type as shown in this code example:

```cpp
EX_CALLBACK_FUNCTION MyRegistryCallback;
```

Then, implement your callback routine as follows:

```cpp
_Use_decl_annotations_
NTSTATUS
  MyRegistryCallback(
    PVOID  CallbackContext,
    PVOID  Argument1,
    PVOID  Argument2
    )
  {
      // Function body
  }
```

The EX_CALLBACK_FUNCTION function type is defined in the Wdm.h header file. To more accurately identify errors when you run the code analysis tools, be sure to add the *Use_decl_annotations* annotation to your function definition. The *Use_decl_annotations* annotation ensures that the annotations that are applied to the EX_CALLBACK_FUNCTION function type in the header file are used. For more information about the requirements for function declarations, see [Declaring Functions by Using Function Role Types for WDM Drivers](https://learn.microsoft.com/windows-hardware/drivers/devtest/declaring-functions-using-function-role-types-for-wdm-drivers). For information about *Use_decl_annotations*, see [Annotating Function Behavior](https://learn.microsoft.com/visualstudio/code-quality/annotating-function-behavior).

## See also

[CmRegisterCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-cmregistercallback)

[CmUnRegisterCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-cmunregistercallback)

[ProbeForRead](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-probeforread)

[**REG_NOTIFY_CLASS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ne-wdm-_reg_notify_class)

[ZwOpenKey](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-zwopenkey)