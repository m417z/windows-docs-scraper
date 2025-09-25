# FILE_NETWORK_PHYSICAL_NAME_INFORMATION structure

## Description

The **FILE_NETWORK_PHYSICAL_NAME_INFORMATION** structure contains the full UNC physical pathname for a file or directory on a remote file share.

## Members

### `FileNameLength`

The length, in bytes, of the physical name in **FileName**.

### `FileName`

The full UNC path of the network file share of the target.

## Remarks

The **FILE_NETWORK_PHYSICAL_NAME_INFORMATION** structure is used to retrieve the network physical name information for a file. This operation can be performed in either of the following ways:

* Call [**ZwQueryInformationFile**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ntqueryinformationfile), passing **FileNetworkPhysicalNameInformation** as the value of **FileInformationClass** and passing a caller-allocated buffer formatted as a **FILE_NETWORK_PHYSICAL_NAME_INFORMATION** structure for the value of **FileInformation**. The **FileHandle** parameter specifies the file target for the name information.

 File system minifilters must use [**FltQueryInformationFile**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltqueryinformationfile) to query the physical name information.

* Create an IRP with major function code [**IRP_MJ_QUERY_INFORMATION**](https://learn.microsoft.com/windows-hardware/drivers/ifs/irp-mj-query-information).

The **FileName** of **FILE_NETWORK_PHYSICAL_NAME_INFORMATION** will contain the network name of the file target handle passed to [**ZwQueryInformationFile**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ntqueryinformationfile). The physical network name returned is in the format of **\;X:\Server\ShareName\Dir1\Dir2\...\FileName**.

If the physical name is longer than the length set in **FileNameLength**, then STATUS_BUFFER_OVERFLOW is returned from [**ZwQueryInformationFile**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ntqueryinformationfile) and **FileNameLength** is updated with the number of bytes required to hold the entire name string. The count of characters in the name is **FileNameLength** / **sizeof**(WCHAR).

In the case where a file is cached on a client and its network physical name is queried, the path returned in **FileName** may not be known to the client cache. The caching system may not associate the cached file with the file opened using the path returned in **FileName**.

The following is an example of querying the network physical name information of a file target using [**ZwQueryInformationFile**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ntqueryinformationfile).

```cpp
NTSTATUS GetPhysicalNetworkName(HANDLE Target, WCHAR *NetworkName, ULONG MaxNetworkNameLength)
{
    NTSTATUS Status;
    IO_STATUS_BLOCK IoStatus;
    ULONG NameInfoLength;
    PFILE_NETWORK_PHYSICAL_NAME_INFORMATION NetFileNameInfo = NULL;

    if ( MaxNetworkNameLength < sizeof(WCHAR) )
    {
        return STATUS_NAME_TOO_LONG;
    }
    if (NetworkName != NULL)
    {
        return STATUS_INVALID_PARAMETER;
    }

    NetworkName[0] = (WCHAR)0;  // initially terminate the output string;

    // set the initial name length, the one WCHAR in NetFileNameInfo.FileName is reserved for the terminating NULL
    NameInfoLength = sizeof(PFILE_NETWORK_PHYSICAL_NAME_INFORMATION) +
                     min(1024, MaxNetworkNameLength - sizeof(WCHAR));
    NetFileNameInfo = (PFILE_NETWORK_PHYSICAL_NAME_INFORMATION)ExAllocatePool(PagedPool, NameInfoLength);

    if (NetFileNameInfo == NULL)
    {
        Status = STATUS_NO_MEMORY;
    }
    else
    {
        Status = ZwQueryInformationFile(Target,
                                        &IoStatus,
                                        NetFileNameInfo,
                                        NameInfoLength,
                                        FileNetworkPhysicalNameInformation);
    }
    if (Status == STATUS_BUFFER_OVERFLOW)
    {
        if (NetFileNameInfo->FileNameLength <= (MaxNetworkNameLength - sizeof(WCHAR)))
        {
            NameInfoLength += sizeof(PFILE_NETWORK_PHYSICAL_NAME_INFORMATION) + NetFileNameInfo->FileNameLength;
            ExFreePool(NetFileNameInfo);
            NetFileNameInfo = (PFILE_NETWORK_PHYSICAL_NAME_INFORMATION)ExAllocatePool(PagedPool, NameInfoLength);
            if (NetFileNameInfo == NULL)
            {
                Status = STATUS_NO_MEMORY;
            }
            else
            {
                Status = ZwQueryInformationFile(Target,
                                                &IoStatus,
                                                NetFileNameInfo,
                                                NameInfoLength,
                                                FileNetworkPhysicalNameInformation);
            }
        }
    }
    if (NetFileNameInfo != NULL)
    {
        if (NT_SUCCESS(Status))
        {
            NameInfoLength = min(NameInfoLength, NetFileNameInfo->FileNameLength);
            RtlCopyMemory(NetworkName, NetFileNameInfo->FileName, NameInfoLength);
            NetworkName[NameInfoLength / sizeof(WCHAR)] = (WCHAR)0;
        }
        ExFreePool(NetFileNameInfo);
    }

    return Status;
}

```

## See also

[**FILE_INFORMATION_CLASS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ne-wdm-_file_information_class)

[**IRP_MJ_QUERY_INFORMATION**](https://learn.microsoft.com/windows-hardware/drivers/ifs/irp-mj-query-information)

[**ZwQueryInformationFile**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ntqueryinformationfile)