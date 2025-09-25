# IBITSExtensionSetup::EnableBITSUploads

## Description

Use the
**EnableBITSUploads** method to enable BITS upload on the virtual directory to which the ADSI object points. This method sets the
[BITSUploadEnabled](https://learn.microsoft.com/windows/desktop/Bits/bits-iis-extension-properties) IIS extension property.

## Return value

This method returns **S_OK** for success. Otherwise, the method failed.

## Remarks

This method turns off the scripting and execute permissions on the virtual directory; you cannot upload files to a virtual directory that has scripting and execute permissions enabled. If the permissions are restored after calling this method, the upload jobs fail with an error code of **BG_E_SERVER_EXECUTE_ENABLED**.

The
**EnableBITSUploads** method fails if the [Task Scheduler](https://learn.microsoft.com/windows/desktop/TaskSchd/task-scheduler-start-page) is disabled.

#### Examples

See the example for the
[IBITSExtensionSetup](https://learn.microsoft.com/windows/desktop/api/bitscfg/nn-bitscfg-ibitsextensionsetup) interface.

## See also

[IBITSExtensionSetup::DisableBITSUploads](https://learn.microsoft.com/windows/desktop/api/bitscfg/nf-bitscfg-ibitsextensionsetup-disablebitsuploads)