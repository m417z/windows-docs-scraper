# IOCTL_TCP_QUERY_INFORMATION_EX IOCTL

## Description

[This control code may be altered or unavailable in future versions of Windows.
Use Internet Protocol Helper API instead of this
control code.]

Retrieves information from the TCP/IP driver.

To perform the **IOCTL_TCP_QUERY_INFORMATION_EX** operation, call the [DeviceIoControl](https://learn.microsoft.com/windows/desktop/api/ioapiset/nf-ioapiset-deviceiocontrol)
function with the following parameters.

```cpp
BOOL DeviceIoControl(
  (HANDLE) hDevice,                  // Open handle to the TCP driver
  IOCTL_TCP_QUERY_INFORMATION_EX,    // dwIoControlCode
  NULL,                              // lpInBuffer (the output buffer is used for input too)
  0,                                 // nInBufferSize
  (LPVOID) lpOutBuffer,              // Pointer to the output buffer
  (DWORD) nOutBufferSize,            // Size of the output buffer
  (LPDWORD) lpBytesReturned,         // Number of bytes returned (if called synchronously)
  (LPOVERLAPPED) lpOverlapped        // OVERLAPPED structure (if called asynchronously)
);
```

## Parameters

### Input buffer

### Input buffer length

### Output buffer

### Output buffer length

### Input/output buffer

### Input/output buffer length

### Status block

Irp->IoStatus.Status is set to STATUS_SUCCESS if the request is successful.

Otherwise, Status to the appropriate error condition as a NTSTATUS code.

For more information, see [NTSTATUS Values](https://learn.microsoft.com/windows-hardware/drivers/kernel/ntstatus-values).

## Remarks

To use **IOCTL_TCP_QUERY_INFORMATION_EX**, you should be familiar with Windows Driver Development, as documented in the [Windows Driver Kit (WDK)](https://learn.microsoft.com/windows-hardware/drivers/download-the-wdk), and specifically with Transport Driver Interface (TDI) drivers.

**Note** To use this control code, include the Windows.h header file. In addition, specifically include Tcpioctl.h, a header file published in the Windows SDK for use with **IOCTL_TCP_QUERY_INFORMATION_EX**, and also Tdiinfo.h and Tdistat.h, header files published in the WDK for TDI driver development.

**Note** Various flags and other constants defined in the Tdiinfo.h WDK header file for the **IOCTL_TCP_QUERY_INFORMATION_EX** operation use the following naming convention.

| Letters | Stand for | Comments |
| --- | --- | --- |
| "AT" | Address Translation | Address resolution such as that provided by ARP (Address Resolution Protocol). |
| "NL" | Network Layer | As in the Open Systems Interconnection (OSI) reference model. |
| "TL" | Transport Layer | As in the OSI reference model. |
| "CL" | Connection-Less | A connectionless protocol based on broadcast packets. |
| "CO" | Connected | A connected protocol based on directed packets. |
| "ER" | Echo Request/Reply | Packet types used by Ping to test TCP/IP connectivity. |
| "IF" | Interface | An interface in the sense used in SNMP. |

The **IOCTL_TCP_QUERY_INFORMATION_EX** operation
retrieves different kinds of information, depending on what the
[TCP_REQUEST_QUERY_INFORMATION_EX](https://learn.microsoft.com/windows/desktop/api/tdiinfo/ns-tdiinfo-tcp_request_query_information_ex_w2k) structure
pointed to by the *lpInBuffer* parameter contains, as described in the following paragraph and example code.

1. Enumerate TDI Entities.

 To retrieve an array of [TDIEntityID](https://learn.microsoft.com/windows/desktop/api/tdiinfo/ns-tdiinfo-tdientityid)
structures that identifies all the TCP entities on the machine, set the **ID.toi_entity.tei_entity**
member of the input structure to **GENERIC_ENTITY**. **ID.toi_class** must then
be set to **INFO_CLASS_GENERIC**, **ID.toi_type** must be set to
**INFO_TYPE_PROVIDER**, and **ID.toi_id** must be set to
**ENTITY_LIST_ID**, or the operation fails with a TDI_INVALID_PARAMETER error code.
The **Context** member of the input structure is ignored when a list is requested.
The output in this case is an array of **TDIEntityID** structures.
The **GetEntityArray** function in the first code example below shows how to retrieve such an array.

2. Obtain Type Information about a Specific TDI Entity.

If the **ID.toi_entity** member of the input
structure identifies a specific entity (as in the case of the [TDIEntityID](https://learn.microsoft.com/windows/desktop/api/tdiinfo/ns-tdiinfo-tdientityid)
structures returned by the enumeration request above), then setting the **ID.toi_class** to
**INFO_CLASS_GENERIC**, the **ID.toi_type** to
**INFO_TYPE_PROVIDER**, and the **ID.toi_id** to
**ENTITY_TYPE_ID** causes one or more flag values to be returned into an **unsigned long** pointed to by the *lpOutBuffer* parameter. These flag values identify the type of the specified entity. Once again, the
**Context** member of the input structure is ignored.

The possible type-flag values that can be returned are shown in the following table.

| Flag | Significance |
| --- | --- |
| AT_ARP | Entity implements ARP (Address Resolution Protocol). |
| AT_NULL | Entity does no address translation. |
| CL_NL_IP | Entity implements IP (Internet Protocol), connectionless on the network layer. |
| CL_NL_IPX | Entity implements IPX (Internetwork Packet Exchange protocol), connectionless on the network layer. |
| CL_TL_NBF | Entity implements NBF (NetBEUI Frame protocol), connectionless on the transport layer. |
| CL_TL_UDP | Entity implements UDP (User Datagram Protocol) connectionless on the transport layer. |
| CO_TL_NBF | Entity implements NBF (NetBEUI Frame protocol), directed packets on the transport layer. |
| CO_TL_SPP | Entity implements SPP (Sequenced Packet Protocol), directed packets on the transport layer. |
| CO_TL_SPX | Entity implements SPX (Sequenced Packet Exchange protocol), directed packets on the transport layer. |
| CO_TL_TCP | Entity implements TCP (Transmission Control Protocol), directed packets on the transport layer. |
| ER_ICMP | Entity implements ICMP (Internet Control Message Protocol) for Echo Request/Reply. |
| IF_GENERIC | Entity implements a generic interface. |
| IF_MIB | Entity implements an interface with SNMP MIB-II support. |

3. Obtain MIB-II Information about an Interface Entity.

If the entity type is IF_MIB, then a MIB request can be sent to it that results in the return of an [IFEntry](https://learn.microsoft.com/windows/desktop/api/tcpioctl/ns-tcpioctl-ifentry) structure. Set the **ID.toi_entity** member of the input
structure to identify the entity, the **ID.toi_class** to
**INFO_CLASS_PROTOCOL**, the **ID.toi_type** to
**INFO_TYPE_PROVIDER**, and the **ID.toi_id** to
**IF_MIB_STATS_ID**.

Note that because [IFEntry](https://learn.microsoft.com/windows/desktop/api/tcpioctl/ns-tcpioctl-ifentry) is a variable-length structure, the output buffer should be allocated not just as "sizeof(IFEntry)" but as "sizeof(IFEntry) + MAX_ADAPTER_DESCRIPTION_LENGTH + 1".

4. Obtain MIB-II Information about a Particular IP Entity.

MIB information can also be retrieved from an IP entity (one whose type is **CL_NL_ENTITY**) by setting the **ID.toi_entity** member to identify the entity, the **ID.toi_class** to
**INFO_CLASS_PROTOCOL**, the **ID.toi_type** to
**INFO_TYPE_PROVIDER**, and the **ID.toi_id** to
**IP_MIB_STATS_ID**. In this case, an [IPSNMPInfo](https://learn.microsoft.com/windows/desktop/api/tcpioctl/ns-tcpioctl-ipsnmpinfo) structure is returned, and the output buffer can be allocated to "sizeof(IPSNMPInfo)".

5. Obtain Address Information about a Particular IP Entity.

If the **ipsi_numaddr** member of the [IPSNMPInfo](https://learn.microsoft.com/windows/desktop/api/tcpioctl/ns-tcpioctl-ipsnmpinfo) structure returned for a particular IP entity is nonzero, an array of [IPAddrEntry](https://learn.microsoft.com/windows/desktop/api/tcpioctl/ns-tcpioctl-ipaddrentry) structures can be retrieved by setting the **ID.toi_entity** member to identify the entity, the **ID.toi_class** to
**INFO_CLASS_PROTOCOL**, the **ID.toi_type** to
**INFO_TYPE_PROVIDER**, and the **ID.toi_id** to
**IP_MIB_ADDRTABLE_ENTRY_ID**. In this case, the output buffer should be allocated to hold an array of size:

`sizeof(IPAddrEntry) * pIpSnmpInfoReturned->ipsi_numaddr`

6. Obtain Interface Information about a Particular IP Address.

More interface information can be retrieved for a given IP address returned in the [IPAddrEntry](https://learn.microsoft.com/windows/desktop/api/tcpioctl/ns-tcpioctl-ipaddrentry) array above by leaving the **ID.toi_entity** member set to identify the IP entity, the **ID.toi_class** set to
**INFO_CLASS_PROTOCOL**, and the **ID.toi_type** set to
**INFO_TYPE_PROVIDER**, and then by setting the **ID.toi_id** to
**IP_INTFC_INFO_ID** and the **Context** member of the [TCP_REQUEST_QUERY_INFORMATION_EX](https://learn.microsoft.com/windows/desktop/api/tdiinfo/ns-tdiinfo-tcp_request_query_information_ex_w2k) structure to the IPv4 or IPv6 address in question.

Allocate an output buffer large enough to contain `sizeof(IPINTERFACEINFO) + MAX_PHYSADDR_SIZE`.

On return, the output buffer contains a filled-in [IPInterfaceInfo](https://learn.microsoft.com/windows/desktop/api/tcpioctl/ns-tcpioctl-ipinterfaceinfo) structure.

#### Examples

The following example shows how to obtain a list of the entities present
on the TCP adapter on the current machine.

```cpp
#define  UNICODE
#define  _WIN32_WINNT  0x0500

#include <stdio.h>
#include <windows.h>
#include <iptypes.h>
#include "winternl.h"
#include "tdiinfo.h"
#include "tdistat.h"
#include "tcpioctl.h"

/*  Function:              GetTCPHandle
    Description:
      Opens a handle to the TCP driver
    Parameters:
      pTCPDriverHandle --  Pointer to a handle variable.
    Return Value (DWORD):  Returns TRUE if successful, and places
                           a valid handle to the TCP driver in the
                           handle pointed to by pTCPDriverHandle, or
                           returns FALSE otherwise, and sets the
                           handle to INVALID_HANDLE_VALUE.
*/
DWORD GetTCPHandle( PHANDLE pTCPDriverHandle )
{
#define FILE_OPEN_IF                    0x00000003
#define FILE_SYNCHRONOUS_IO_NONALERT    0x00000020
#define OBJ_CASE_INSENSITIVE            0x00000040L

typedef NTSTATUS (NTAPI *P_NT_CREATE_FILE)(
    OUT PHANDLE              FileHandle,
    IN  ACCESS_MASK          DesiredAccess,
    IN  POBJECT_ATTRIBUTES   ObjectAttributes,
    OUT PIO_STATUS_BLOCK     IoStatusBlock,
    IN  PLARGE_INTEGER       AllocationSize OPTIONAL,
    IN  ULONG                FileAttributes,
    IN  ULONG                ShareAccess,
    IN  ULONG                CreateDisposition,
    IN  ULONG                CreateOptions,
    IN  PVOID                EaBuffer OPTIONAL,
    IN  ULONG                EaLength );

  HINSTANCE hNtDLL;
  P_NT_CREATE_FILE pNtCreateFile;
  NTSTATUS rVal;
  WCHAR TCPDriverName[] = DD_TCP_DEVICE_NAME;

  OBJECT_ATTRIBUTES  objectAttributes;
  IO_STATUS_BLOCK    ioStatusBlock;
  UNICODE_STRING     UnicodeStr;

  *pTCPDriverHandle = INVALID_HANDLE_VALUE;

  if( ( hNtDLL = LoadLibrary( L"ntdll" ) ) == NULL )
    return( FALSE );

  pNtCreateFile = (P_NT_CREATE_FILE) GetProcAddress( hNtDLL,
            "NtCreateFile" );
  if( pNtCreateFile == NULL )
    return( FALSE );

  UnicodeStr.Buffer = TCPDriverName;
  UnicodeStr.Length = (USHORT)(wcslen(TCPDriverName) * sizeof(WCHAR));
  UnicodeStr.MaximumLength = UnicodeStr.Length + sizeof(UNICODE_NULL);

  objectAttributes.Length = sizeof( OBJECT_ATTRIBUTES );
  objectAttributes.ObjectName = &UnicodeStr;
  objectAttributes.Attributes = OBJ_CASE_INSENSITIVE;
  objectAttributes.RootDirectory = NULL;
  objectAttributes.SecurityDescriptor = NULL;
  objectAttributes.SecurityQualityOfService = NULL;

  rVal = pNtCreateFile( pTCPDriverHandle,
                       SYNCHRONIZE | GENERIC_EXECUTE,
                       &objectAttributes,
                       &ioStatusBlock,
                       NULL,
                       FILE_ATTRIBUTE_NORMAL,
                       FILE_SHARE_READ | FILE_SHARE_WRITE,
                       FILE_OPEN_IF,
                       FILE_SYNCHRONOUS_IO_NONALERT,
                       NULL,
                       0 );

  if( rVal < 0 )
  {
    printf( "\nFailed to create TCP Driver handle; NT status code = %d.", rVal );
    *pTCPDriverHandle = INVALID_HANDLE_VALUE;
    return( FALSE );
  }
  return( TRUE );
}

/*  Function:              GetEntityList
    Description:
      Allocates a buffer for and retrieves an array of TDIEntityID
    structures that identifies the entities supported by
    the TCP/IP device driver.
    Parameters:
      TCPDriverHandle  --  An open handle to the TCP Driver; if
            no such handle is available,
            may be INVALID_HANDLE_VALUE.
      lplpEntities     --  Pointer to a buffer that contains
            the array of TDIEntityID structures.
            Must be freed by the calling process
            using LocalFree( ).
    Return Value:
      DWORD  --  the number of entity structures in the returned array
*/
DWORD GetEntityArray( IN HANDLE TCPDriverHandle,
    OUT TDIEntityID **lplpEntities )
{
  TCP_REQUEST_QUERY_INFORMATION_EX  req;
  DWORD arrayLen = sizeof(TDIEntityID) * MAX_TDI_ENTITIES;
  DWORD bufferLen = arrayLen;
  TDIEntityID * pEntity = NULL;
  NTSTATUS status = TDI_SUCCESS;
  DWORD temporaryHandle = 0;
  int i;

// First, if the handle passed in is not valid, try to obtain one.
  if( TCPDriverHandle == INVALID_HANDLE_VALUE )
  {
    if( GetTCPHandle( &TCPDriverHandle ) == FALSE )
    {
      *lplpEntities = NULL;
      return( 0 );
    }
    temporaryHandle = TRUE;
  }

// Next, set up the input structure for the IOCTL operation.
  req.ID.toi_entity.tei_entity    = GENERIC_ENTITY;
  req.ID.toi_entity.tei_instance  = 0;
  req.ID.toi_class                = INFO_CLASS_GENERIC;
  req.ID.toi_type                 = INFO_TYPE_PROVIDER;
  req.ID.toi_id                   = ENTITY_LIST_ID;

// The loop below is defensively engineered:
// (1)  In the first place, it is unlikely that more
//     than MAX_TDI_ENTITIES of TCP/IP entities exist,
//     so the loop should execute only once.
// (2)  Execution is limited to 4 iterations to rule out
//     infinite looping in case of parameter corruption. Only 2
//     iterations should ever be necessary unless entities are
//     being added while the loop is running.
  for( i = 0; i < 4; ++i )
  {
    if( pEntity != NULL )
    {
      LocalFree( pEntity );
      pEntity = NULL;
      bufferLen = arrayLen;
    }

    if( arrayLen == 0 )
      break;

    pEntity = (TDIEntityID *) LocalAlloc( LMEM_FIXED, bufferLen );
    if( pEntity == NULL )
    {
      arrayLen = 0;
      break;
    }

    if( !DeviceIoControl( TCPDriverHandle, // Handle to TCP driver
                          IOCTL_TCP_QUERY_INFORMATION_EX, // Cmd code
                          &req,            // Pointer to input buffer
                          sizeof(req),     // Size of ipt buffer
                          pEntity,         // Ptr to output buffer
                          bufferLen,       // Size of output buffer
                          &arrayLen,       // Actual size of array
                          NULL ) )
      status = GetLastError( );

    // Even if the output buffer is too small, the TCP driver
    // returns a status of TDI_SUCCESS; it is the value returned in
    // arrayLen that indicates whether the entire array was
    // successfully copied to the output buffer.
    if( status == TDI_SUCCESS )
    {
      if( arrayLen && ( arrayLen <= bufferLen ) )
        break;
    }
    else
      arrayLen = 0;
  }
  if( temporaryHandle )
    CloseHandle( TCPDriverHandle );

  *lplpEntities = pEntity;
  return( (DWORD)( arrayLen / sizeof(TDIEntityID) ) );
}

int main( )
{
  DWORD i;
  DWORD entityCount;
  TDIEntityID
    *entityArray,
    *entityPtr;

  if( !( entityCount = GetEntityArray( INVALID_HANDLE_VALUE,
    &entityArray ) ) )
    return( 1 );

  entityPtr = entityArray;
  printf( "\n\nList of %d Transport Driver Interface Entities on this machine:\n", entityCount );

  for( i = 0; i < entityCount; ++i )
  {
    printf( "\n  Entity #%d:\n    Category (tei_entity) is ", i );
    switch( entityPtr->tei_entity )
    {
      case GENERIC_ENTITY:
        printf( "Generic." );
        break;
      case CL_NL_ENTITY:
        printf( "Connectionless Network-Layer (CL_NL)" );
        break;
      case CO_NL_ENTITY:
        printf( "Connected Network-Layer (CO_NL)" );
        break;
      case CL_TL_ENTITY:
        printf( "Connectionless Transport-Layer (CL_TL)" );
        break;
      case CO_TL_ENTITY:
        printf( "Connected Transport-Layer (CO_TL)" );
        break;
      case AT_ENTITY:
        printf( "Address Translation (AT)" );
        break;
      case IF_ENTITY:
        printf( "Interface (IF)" );
        break;
      case ER_ENTITY:
        printf( "Echo Request/Response (ER)" );
        break;
      default:
        printf( "[Unidentified Entity Type] = 0x%x",
        entityPtr->tei_entity );
    }
    printf( "\n Instance (tei_instance) = %d\n",
        entityPtr->tei_instance );

    ++entityPtr;
  }

//  Free the entity-array buffer before quitting.
    LocalFree( entityArray );

  return( 0 );
}

```

## See also

[DeviceIoControl](https://learn.microsoft.com/windows/desktop/api/ioapiset/nf-ioapiset-deviceiocontrol)

[Internet Protocol Helper API](https://learn.microsoft.com/windows/desktop/IpHlp/ip-helper-start-page)

[Management Information Base Reference](https://learn.microsoft.com/previous-versions/windows/desktop/mib/management-information-base-reference)