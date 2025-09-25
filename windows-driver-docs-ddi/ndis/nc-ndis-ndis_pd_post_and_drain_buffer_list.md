# NDIS_PD_POST_AND_DRAIN_BUFFER_LIST callback function

## Description

The PacketDirect (PD) platform calls a PD-capable miniport driver's
*PDPostAndDrainBufferList* function to post [PD_BUFFER](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_pd_buffer) structures to PD transmit/receive queues and draining any previously posted **PD_BUFFER** structures that have been completed.

**Note** You must declare the function by using the **NDIS_PD_POST_AND_DRAIN_BUFFER_LIST** type. For more
information, see the following Examples section.

## Parameters

### `Queue` [in, out]

A pointer to the transmit or receive queue that will receive posted buffers and will have completed buffers removed.

### `PostBufferListHead` [in, out]

The head of the post list. The provider removes the buffers in this list and adds them into the **Queue**.

### `DrainBufferListTail` [in, out]

The tail of the drain list. The provider removes any completed buffers from the **Queue** and adds them to this list.

### `MaxDrainCount` [in]

The maximum amount of [PD_BUFFER](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_pd_buffer) structures to drain. The provider must ensure not exceed this amount. A set of partial **PD_BUFFER** structures that make up a single L2 packet count is 1.

## Return value

This callback function does not return a value.

## Remarks

The provider removes buffers from the PostBufferList and places them into the queue, starting with the head buffer in the list and advancing to the next buffer until either the PostBufferList is empty or the queue is full (or near full). The provider advanced to the PostListHead and returns the new list head to the caller. The provider also removes any completed buffers from the queue and inserts them into the tail of the DrainBufferList and returns the new DrainBufferList tail to the client.

**Note** The provider should drain as many buffers as it can in order to open up room for the buffers being posted. The PostBufferList and DrainBufferList are guaranteed to be disjoint buffer lists (The client never provides the head of a buffer list as the PostBufferListHead and the tail of that same list as DrainBufferListTail).

The client can also pass an empty post buffer list to just drain completed buffers without posting any new buffers. The client can also set the MaxDrainCount to 0 to just post new buffers without draining any completed buffers. In rare cases, the client may invoke the call with both an empty post buffer list and the MaxDrainCount to 0. The provider must not assume otherwise and handle such a call properly such as a no-operation.

### Examples

To define a *PDPostAndDrainBufferList* function, you must first provide a function declaration that identifies the type of function you're defining. Windows provides a set of function types for drivers. Declaring a function using the function types helps [Code Analysis for Drivers](https://learn.microsoft.com/windows-hardware/drivers/devtest/code-analysis-for-drivers), [Static Driver Verifier](https://learn.microsoft.com/windows-hardware/drivers/devtest/static-driver-verifier) (SDV), and other verification tools find errors, and it's a requirement for writing drivers for the Windows operating system.

For example, to define a *PDPostAndDrainBufferList* function that is named "MyPDPostAndDrainBufferList", use the **NDIS_PD_POST_AND_DRAIN_BUFFER_LIST** type as shown in this code example:

```
NDIS_PD_POST_AND_DRAIN_BUFFER_LIST MyPDPostAndDrainBufferList;
```

Then, implement your function as follows:

```
_Use_decl_annotations_
VOID
 MyPDPostAndDrainBufferList(
    NDIS_PD_QUEUE*  Queue,
    PD_BUFFER**  PostBufferListHead,
    PD_BUFFER*** DrainBufferListTail,
    ULONG  MaxDrainCount
    )
  {...}
```

The **NDIS_PD_POST_AND_DRAIN_BUFFER_LIST** function type is defined in the Ntddndis.h header file. To more accurately identify errors when you run the code analysis tools, be sure to add the _Use_decl_annotations_ annotation to your function definition. The _Use_decl_annotations_ annotation ensures that the annotations that are applied to the **NDIS_PD_POST_AND_DRAIN_BUFFER_LIST** function type in the header file are used. For more information about the requirements for function declarations, see [Declaring Functions by Using Function Role Types for NDIS Drivers](https://learn.microsoft.com/windows-hardware/drivers/devtest/declaring-functions-by-using-function-role-types-for-ndis-drivers).

For information about _Use_decl_annotations_, see [Annotating Function Behavior](https://learn.microsoft.com/visualstudio/code-quality/annotating-function-behavior).

The following is an example code snippet that illustrates the pointer indirections for this function.

```cpp
PD_BUFFER* PostHead = NULL;
PD_BUFFER** PostTail = &PostHead;
PD_BUFFER* DrainHead = NULL;
PD_BUFFER** DrainTail = &DrainHead;

PD_BUFFER* bufX = <allocated PD_BUFFER>;

bufX->NextPDBuffer = NULL;
*PostTail = bufX;
PostTail = &bufX->NextPDBuffer;

// BEFORE:
//PostHead == bufX
//PostTail == &bufZ->NextPDBuffer
//DrainHead == NULL
//DrainTail == &DrainHead

NDIS_PD_POST_AND_DRAIN_BUFFER_LIST(
          Queue,
          &PostHead,
          &DrainTail,
          32);

// AFTER:
//PostHead == bufY
//PostTail == &bufZ->NextPDBuffer
//DrainHead == buf1
//DrainTail == &buf5->NextPDBuffer

```