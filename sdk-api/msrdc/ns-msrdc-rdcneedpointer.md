# RdcNeedPointer structure

## Description

The **RdcNeedPointer** structure describes an array
of [RdcNeed](https://learn.microsoft.com/windows/win32/api/msrdc/ns-msrdc-rdcneed) structures. The
**RdcNeedPointer** structure is used as both input and output
by the [IRdcComparator::Process](https://learn.microsoft.com/previous-versions/windows/desktop/api/msrdc/nf-msrdc-irdccomparator-process) method.

## Members

### `m_Size`

Contains the number of [RdcNeed](https://learn.microsoft.com/windows/win32/api/msrdc/ns-msrdc-rdcneed) structures in array pointed
to by **m_Data**.

### `m_Used`

When the structure is passed to the
[IRdcComparator::Process](https://learn.microsoft.com/previous-versions/windows/desktop/api/msrdc/nf-msrdc-irdccomparator-process) method, this member
should be zero. On return this member will contain the number of
[RdcNeed](https://learn.microsoft.com/windows/win32/api/msrdc/ns-msrdc-rdcneed) structures that were filled with data.

### `m_Data`

Address of array of [RdcNeed](https://learn.microsoft.com/windows/win32/api/msrdc/ns-msrdc-rdcneed) structures that describe the
chunks required from the source and seed data.

## See also

[IRdcComparator::Process](https://learn.microsoft.com/previous-versions/windows/desktop/api/msrdc/nf-msrdc-irdccomparator-process)

[RdcNeed](https://learn.microsoft.com/windows/win32/api/msrdc/ns-msrdc-rdcneed)

[Remote Differential Compression Structures](https://learn.microsoft.com/previous-versions/windows/desktop/rdc/remote-differential-compression-structures)