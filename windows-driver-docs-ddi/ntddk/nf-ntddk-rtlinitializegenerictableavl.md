## Description

The **RtlInitializeGenericTableAvl** routine initializes a generic table using Adelson-Velsky/Landis (AVL) trees.

## Parameters

### `Table` [out]

A pointer to a caller-allocated buffer, which must be at least **sizeof**([RTL_AVL_TABLE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_rtl_avl_table)) bytes in size, to contain the initialized generic table structure.

### `CompareRoutine` [in]

An entry point of a comparison callback routine, declared as follows:

```cpp
RTL_GENERIC_COMPARE_RESULTS
(*PRTL_AVL_COMPARE_ROUTINE) (
    __in struct _RTL_AVL_TABLE  *Table,
    __in PVOID  FirstStruct,
    __in PVOID  SecondStruct
    );
```

The *CompareRoutine* parameters are as follows:

#### Table (CompareRoutine)

A pointer to the generic table.

#### FirstStruct

A pointer to the first item to be compared.

#### SecondStruct

A pointer to the second item to be compared.

The *CompareRoutine* must strictly track the ordering of all elements in the generic table so that it can identify any particular element. The caller-defined structure for element data usually includes a member whose value is unique and can be used as a sorting key. All *Rtl...GenericTableAvl* routines that call the *CompareRoutine* take a buffer pointer as a parameter, which is passed in turn to the *CompareRoutine*. The buffer contains a caller-supplied key value to be matched by the *CompareRoutine* to the key of the element that is being searched for.

Given two such key values, the *CompareRoutine* returns **GenericLessThan**, **GenericGreaterThan**, or **GenericEqual**.

### `AllocateRoutine` [in]

An entry point of an allocation callback routine, declared as follows:

```cpp
PVOID
(*PRTL_AVL_ALLOCATE_ROUTINE) (
    __in struct _RTL_AVL_TABLE  *Table,
    __in CLONG  ByteSize
    );
```

The *AllocateRoutine* parameters are as follows:

#### Table (AllocateRoutine)

A pointer to the generic table.

#### ByteSize

The number of bytes to allocate.

For each new element, the *AllocateRoutine* is called to allocate memory for caller-supplied data plus some additional memory for use by the *Rtl...GenericTableAvl* routines. Note that because of this "additional memory," caller-supplied routines must not access the first **sizeof**(RTL_BALANCED_LINKS) bytes of any element in the generic table.

### `FreeRoutine` [in]

An entry point of a deallocation callback routine, declared as follows:

```cpp
VOID
(*PRTL_AVL_FREE_ROUTINE) (
    __in struct _RTL_AVL_TABLE  *Table,
    __in PVOID  Buffer
    );
```

The *FreeRoutine* parameters are as follows:

#### Table (FreeRoutine)

A pointer to the generic table.

#### Buffer

A pointer to the element that is being deleted.

*Rtl...GenericTableAvl* routines call the *FreeRoutine* to deallocate memory for elements to be deleted from the generic table. The *FreeRoutine* is the opposite of the *AllocateRoutine*.

### `TableContext` [in, optional]

An optional pointer to a caller-supplied context for the generic table. This parameter can be **NULL**.

## Return value

None

## Remarks

File systems call **RtlInitializeGenericTableAvl** to initialize a generic table to store file system-specific data, such as name-lookup information for currently open files. The sort order, structure, and contents of the elements are caller-defined.

File systems must call **RtlInitializeGenericTableAvl** to initialize the generic table before they use any other *Rtl...GenericTableAvl* routines on the new generic table. The initialized generic table structure should be considered opaque.

Callers of the *Rtl...GenericTableAvl* routines are responsible for exclusively synchronizing access to the generic table. An exclusive fast mutex is the most efficient synchronization mechanism to use for this purpose.

The caller-supplied *CompareRoutine* is called before the *AllocateRoutine* to locate an appropriate location at which a new element should be inserted. The *CompareRoutine* also is called before the *FreeRoutine* to locate an element to be deleted.

The **RtlInitializeGenericTableAvl** routine explicitly allocates a generic table that uses AVL trees. Use of this routine and the other *Rtl...GenericTableAvl* routines is necessary when AVL tree based tables are desired and RTL_USE_AVL_TABLES is not defined before including *Ntddk.h*.

Callers of **RtlInitializeGenericTableAvl** must be running at IRQL <= DISPATCH_LEVEL. Note that if *Rtl...GenericTableAvl* routines are to be used at IRQL DISPATCH_LEVEL, the *CompareRoutine*, *AllocateRoutine*, and *FreeRoutine* must all be nonpageable code, and the *AllocateRoutine* should allocate memory from nonpaged pool.

## See also

[ExInitializeFastMutex](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exinitializefastmutex)

[RtlDeleteElementGenericTableAvl](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-rtldeleteelementgenerictableavl)

[RtlEnumerateGenericTableAvl](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-rtlenumerategenerictableavl)

[RtlGetElementGenericTableAvl](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-rtlgetelementgenerictableavl)

[RtlInitializeGenericTable](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-rtlinitializegenerictable)

[RtlInsertElementGenericTableAvl](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-rtlinsertelementgenerictableavl)

[RtlLookupElementGenericTableAvl](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-rtllookupelementgenerictableavl)

[RtlNumberGenericTableElementsAvl](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-rtlnumbergenerictableelementsavl)