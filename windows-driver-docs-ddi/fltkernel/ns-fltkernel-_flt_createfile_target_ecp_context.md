# _FLT_CREATEFILE_TARGET_ECP_CONTEXT structure

## Description

The **FLT_CREATEFILE_TARGET_ECP_CONTEXT** structure is an extra create parameter (ECP) used to return reparse target information back to the caller of [FltCreateFileEx2](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltcreatefileex2).

## Members

### `Instance`

The filter instance attached to the adjusted target.

### `Volume`

The adjusted target volume.

### `FileNameInformation`

The file information for the adjusted target.

### `Flags`

Flags controlling the reparse operation. This value can be either 0 or the following.

| Value | Meaning |
| --- | --- |
| **FLTTCFL_AUTO_REPARSE** | Request that the [FltCreateFileEx2](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltcreatefileex2) attempt a reparse operation when a target is not found with the original file information. |

## Remarks

When a caller of [FltCreateFileEx2](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltcreatefileex2) wishes to enable reparsing for a volume target, a **FLT_CREATEFILE_TARGET_ECP_CONTEXT** can be included as an ECP to the ECP list in the *DriverContext* parameter. If this ECP is present, **FltCreateFileEx2** will adjust the target device for the create operation and attempt to find a filtered instance of a volume appropriate for the given file information. If the filter manager does not find a corresponding instance for the caller on the target volume, it will set the **Volume** and **FileNameInformation** members of **FLT_CREATEFILE_TARGET_ECP_CONTEXT** for the new target. The caller can then use this information to decide how best to proceed.

If the caller of [FltCreateFileEx2](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltcreatefileex2) intends to handle the reparse operation itself, the **FLTTCFL_AUTO_REPARSE** flag is cleared from the **Flags** member. In this case, **FltCreateFileEx2** will place the initial target adjustment information in the ECP and then will return, ending the file create attempt.

 If the values in **Instance**, **Volume**, or **FileNameInformation** are set in an acknowledged ECP, they are referenced objects. A caller of [FltCreateFileEx2](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltcreatefileex2) is responsible for calling [FltObjectDereference](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltobjectdereference) for **Instance** and **Volume**, and [FltReleaseFileNameInformation](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltreleasefilenameinformation) for **FileNameInformation**.

The following example routine demonstrates how a minifilter can call [FltCreateFileEx2](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltcreatefileex2) with **FLT_CREATEFILE_TARGET_ECP_CONTEXT** to handle a reparse to a different volume when required to find a file target.

```
NTSTATUS
CrossVolumeCreate(
    _In_ PUNICODE_STRING FileName,
    _In_ PFLT_FILTER Filter,
    _In_ PFLT_INSTANCE Instance,
    _Inout_ PIO_STATUS_BLOCK IoStatus,
    _Out_ PHANDLE Handle,
    _Outptr_ PFILE_OBJECT *FileObject
    )
/*++

Routine Description:

     Issues a targeted create and handles cross volume reparse.

Arguments:

    FileName - The name of the file to open

    Filter – The filter issuing the create

    Instance - The filter instance for the targeted create

    IoStatus - Receives the operation status

    Handle - Receives the file handle

    FileObject - Receives the file object

Return Value:

    status of the operation

--*/
{
    PFLT_CREATEFILE_TARGET_ECP_CONTEXT ecpContext;
    PECP_LIST ecpList;
    PFLT_FILE_NAME_INFORMATION fileNameInformation;
    IO_DRIVER_CREATE_CONTEXT myCreateContext;
    OBJECT_ATTRIBUTES objAttr;
    NTSTATUS status;

    ecpContext = NULL;
    ecpList = NULL;
    fileNameInformation = NULL;
    status = STATUS_SUCCESS;

    InitializeObjectAttributes( &objAttr,
                                FileName,
                                OBJ_KERNEL_HANDLE,
                                NULL,
                                NULL );

    //
    //  First we optimistically send a targeted create that is not
    //  setup to handle cross-volume reparse.
    //

    status = FltCreateFileEx2( Filter,
                               Instance,
                               Handle,
                               FileObject,
                               FILE_READ_DATA|FILE_WRITE_DATA,
                               &objAttr,
                               IoStatus,
                               NULL,
                               0,
                               FILE_SHARE_READ | FILE_SHARE_WRITE | FILE_SHARE_DELETE,
                               FILE_OPEN_IF,
                               FILE_NON_DIRECTORY_FILE | FILE_SYNCHRONOUS_IO_NONALERT,
                               NULL,
                               0,
                               IO_IGNORE_SHARE_ACCESS_CHECK,
                               NULL );

    if (!NT_SUCCESS(status)) {

        if ((status != STATUS_INVALID_DEVICE_OBJECT_PARAMETER) &&
            (status != STATUS_MOUNT_POINT_NOT_RESOLVED)) {

            goto CrossVolumeCreateExit;
        }

    } else {

        //
        //  The create succeeded. There must not have been a cross-volume
        //  reparse.
        //

        goto CrossVolumeCreateExit;
    }

    //
    //  The create failed traversing a cross-volume link.
    //  Issue another create with a targeting ECP so that
    //  we can handle cross-volume reparse.
    //

    status = FltAllocateExtraCreateParameterList( Filter,
                                                  0,
                                                  &ecpList );
    if (!NT_SUCCESS( status )) {
        goto CrossVolumeCreateExit;
    }

    status = FltAllocateExtraCreateParameter( Filter,
                                              &GUID_ECP_FLT_CREATEFILE_TARGET,
                                              sizeof(FLT_CREATEFILE_TARGET_ECP_CONTEXT),
                                              0,
                                              NULL,
                                              POOL_TAG,
                                              &ecpContext );

    if (!NT_SUCCESS( status )) {
        goto CrossVolumeCreateExit;
    }

    //
    //  Initialize the ECP with the FLTTCFL_AUTO_REPARSE flag which
    //  tells filter manager to handle the cross-volume reparse
    //  internally when possible (when it can find our instance
    //  on the target volume). If this flag is not set, the filter will
    //  be responsible for calling FltCreateFileEx2 with appropriate
    //  Instance parameter.
    //

    ecpContext->Flags = FLTTCFL_AUTO_REPARSE;

    ecpContext->Instance = NULL;
    ecpContext->Volume = NULL;
    ecpContext->FileNameInformation = NULL;

    status = FltInsertExtraCreateParameter( Filter,
                                            ecpList,
                                            ecpContext );
    if (!NT_SUCCESS( status )) {
        goto CrossVolumeCreateExit;
    }

    IoInitializeDriverCreateContext( &myCreateContext );
    myCreateContext.ExtraCreateParameter = ecpList;

    InitializeObjectAttributes( &objAttr,
                                FileName,
                                OBJ_KERNEL_HANDLE,
                                NULL,
                                NULL );

    status = FltCreateFileEx2( Filter,
                               Instance,
                               Handle,
                               FileObject,
                               FILE_READ_DATA|FILE_WRITE_DATA,
                               &objAttr,
                               IoStatus,
                               NULL,
                               0,
                               FILE_SHARE_READ | FILE_SHARE_WRITE | FILE_SHARE_DELETE,
                               FILE_OPEN_IF,
                               FILE_NON_DIRECTORY_FILE | FILE_SYNCHRONOUS_IO_NONALERT,
                               NULL,
                               0,
                               IO_IGNORE_SHARE_ACCESS_CHECK,
                               &myCreateContext );

    if (!NT_SUCCESS(status)) {

        if ((status != STATUS_INVALID_DEVICE_OBJECT_PARAMETER) &&
            (status != STATUS_MOUNT_POINT_NOT_RESOLVED)) {

            goto CrossVolumeCreateExit;
        }

    } else {

        goto CrossVolumeCreateExit;
    }

    //
    //  Filter manager should have acknowledged the ECP. If it
    //  is not acknowledged, it does not contain any cross-volume
    //  targeting information.
    //

    if (!FltIsEcpAcknowledged( Filter, ecpContext)) {
        goto CrossVolumeCreateExit;
    }

    //
    //  Filter manager could not automatically handle the
    //  cross-volume traversal. We choose to send the create
    //  to the top of the stack on the target volume indicated
    //  in the targeting ECP.
    //

    //
    //  The ECP may contain pointers to referenced objects. We
    //  need to deal with those references before reusing the
    //  ECP.
    //

    if (ecpContext->Volume != NULL) {
        FltObjectDereference( ecpContext->Volume );
        ecpContext->Volume = NULL;
    }

    //
    //  Note:  since we flagged the ECP to automatically handle
    //  cross-volume reparse, the create should have failed after
    //  we traversed a mountpoint only if our filter did not have
    //  an instance on the target volume. In that case we would
    //  expect the Instance field in the ECP to be NULL. We still
    //  demonstrate derefing the instance for the general case.
    //

    if (ecpContext->Instance != NULL) {
        FltObjectDereference( ecpContext->Instance );
        ecpContext->Instance = NULL;
    }

    fileNameInformation = ecpContext->FileNameInformation;
    ecpContext->FileNameInformation = NULL;

    //
    //  Tell filter manager to not handle the cross-volume
    //  reparse itself. Presumably a filter would do this if it
    //  did not want the create automatically targeted at its
    //  instance on another volume.
    //

    ecpContext->Flags = 0;

    //
    //  Reinitialize the targeting ECP to it can be reused.
    //

    FltPrepareToReuseEcp( Filter, ecpContext );

    IoInitializeDriverCreateContext( &myCreateContext );
    myCreateContext.ExtraCreateParameter = ecpList;

    InitializeObjectAttributes( &objAttr,
                                &fileNameInformation->Name,
                                OBJ_KERNEL_HANDLE,
                                NULL,
                                NULL );

    status = FltCreateFileEx2( Filter,
                               NULL,
                               Handle,
                               FileObject,
                               FILE_READ_DATA|FILE_WRITE_DATA,
                               &objAttr,
                               IoStatus,
                               NULL,
                               0,
                               FILE_SHARE_READ | FILE_SHARE_WRITE | FILE_SHARE_DELETE,
                               FILE_OPEN_IF,
                               FILE_NON_DIRECTORY_FILE | FILE_SYNCHRONOUS_IO_NONALERT,
                               NULL,
                               0,
                               IO_IGNORE_SHARE_ACCESS_CHECK,
                               &myCreateContext );

    if (!NT_SUCCESS(status)) {

        if ((status != STATUS_INVALID_DEVICE_OBJECT_PARAMETER) &&
            (status != STATUS_MOUNT_POINT_NOT_RESOLVED)) {

            goto CrossVolumeCreateExit;
        }

        //
        //  We hit another cross-volume link. For the purposes of
        //  this example we are just giving up. An actual filter
        //  would determine the next target instance based on the
        //  information provided in the targeting ECP. Some of the
        //  possibilities are:
        //  1) If the Instance field in the ECP is available, target
        //     the create to this instance.
        //  2) If the Instance field is NULL, attempt to attach
        //     an instance based on the Volume parameter in the ECP
        //     and then target that new instance.
        //  3) Use the FileNameInformation provided in the ECP and a
        //     NULL instance to target the top of the other
        //     volume's stack.
        //

    } else {

        goto CrossVolumeCreateExit;
    }

CrossVolumeCreateExit:

    if (ecpContext != NULL &&
        FltIsEcpAcknowledged( Filter, ecpContext)) {

        FltRemoveExtraCreateParameter( Filter,
                                       ecpList,
                                       &GUID_ECP_FLT_CREATEFILE_TARGET,
                                       &ecpContext,
                                       NULL );

        if (ecpContext->Instance != NULL) {
            FltObjectDereference( ecpContext->Instance );
        }

        if (ecpContext->Volume != NULL) {
            FltObjectDereference( ecpContext->Volume );
        }

        if (ecpContext->FileNameInformation != NULL) {
            FltReleaseFileNameInformation( ecpContext->FileNameInformation );
        }

        FltFreeExtraCreateParameter( Filter, ecpContext );
    }

    if (ecpList != NULL) {
        FltFreeExtraCreateParameterList( Filter, ecpList );
    }

    if (fileNameInformation != NULL) {
        FltReleaseFileNameInformation( fileNameInformation );
    }

    return status;
}

```

## See also

[FltCreateFileEx2](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltcreatefileex2)

[FltObjectDereference](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltobjectdereference)

[FltReleaseFileNameInformation](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltreleasefilenameinformation)