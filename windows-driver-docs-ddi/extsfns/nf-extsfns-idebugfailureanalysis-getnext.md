# IDebugFailureAnalysis::GetNext

## Description

 The **GetNext** method searches a [DebugFailureAnalysis](https://learn.microsoft.com/windows-hardware/drivers/ddi/extsfns/nn-extsfns-idebugfailureanalysis2) object for the next [FA entry](https://learn.microsoft.com/windows-hardware/drivers/debugger/failure-analysis-entries), after a given FA entry, that satisfies conditions specified by the *Tag* and *TagMask* parameters.

## Parameters

### `Entry` [in]

A pointer to an [FA_ENTRY](https://learn.microsoft.com/windows-hardware/drivers/ddi/extsfns/ns-extsfns-_fa_entry) structure. The search starts after this [FA entry](https://learn.microsoft.com/windows-hardware/drivers/debugger/failure-analysis-entries). If this parameter is **NULL**, the starts at the beginning of the collection of FA entries.

### `Tag` [in]

A value in the [FA_TAG](https://learn.microsoft.com/windows-hardware/drivers/debugger/writing-an-analysis-extension-to-extend--analyze) enumeration.

### `TagMask` [in]

A mask that restricts the search to a subset of all possible tags. See Remarks. To search all possible tags, set this parameter to **DEBUG_FLR_MASK_ALL**.

## Return value

If the [DebugFailureAnalysis](https://learn.microsoft.com/windows-hardware/drivers/ddi/extsfns/nn-extsfns-idebugfailureanalysis2) object has an [FA entry](https://learn.microsoft.com/windows-hardware/drivers/debugger/failure-analysis-entries), after the given entry, that satisfies the conditions, this method returns a pointer to the [FA_ENTRY](https://learn.microsoft.com/windows-hardware/drivers/ddi/extsfns/ns-extsfns-_fa_entry) structure. Otherwise, this method returns **NULL**.

## Remarks

This method searches for an [FA_ENTRY](https://learn.microsoft.com/windows-hardware/drivers/ddi/extsfns/ns-extsfns-_fa_entry) structure that satisfies this condition:

entry->Tag & *TagMask* == *Tag*

Tags are defined in extsfns.h as values of the [DEBUG_FLR_PARAM_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/extsfns/ne-extsfns-_debug_flr_param_type) enumeration, which is also called the [FA_TAG](https://learn.microsoft.com/windows-hardware/drivers/debugger/writing-an-analysis-extension-to-extend--analyze) enumeration. The tags are arranged in groups so that you can use *TagMask* to search within a particular group. For example there is a group of tags related to pool errors. The numerical values assigned to the tags in this group are in the range 0x400, 0x401 ... 0x406. Every [FA_ENTRY](https://learn.microsoft.com/windows-hardware/drivers/ddi/extsfns/ns-extsfns-_fa_entry) that has a tag in this group satisfies the following condition:

`entry->Tag & 0xFFFFFF00 == 0x400`

The following code snippet shows a portion of the [FA_TAG](https://learn.microsoft.com/windows-hardware/drivers/debugger/writing-an-analysis-extension-to-extend--analyze) enumeration.

```cpp
...
// Pool
DEBUG_FLR_POOL_ADDRESS = 0x400,
DEBUG_FLR_SPECIAL_POOL_CORRUPTION_TYPE,
DEBUG_FLR_CORRUPTING_POOL_ADDRESS,
DEBUG_FLR_CORRUPTING_POOL_TAG,
DEBUG_FLR_FREED_POOL_TAG,
DEBUG_FLR_LEAKED_SESSION_POOL_TAG,
DEBUG_FLR_CLIENT_DRIVER,

// Filesystem
DEBUG_FLR_FILE_ID = 0x500,
DEBUG_FLR_FILE_LINE,
...
```

#### Examples

**Example 1**

The following example shows how to find all failure analysis entries that have a tag equal to **DEBUG_FLR_MANAGED_EXCEPTION_OBJECT**. Assume `pAnalysis` is a pointer to an [IDebugFailureAnalysis2](https://learn.microsoft.com/windows-hardware/drivers/ddi/extsfns/nn-extsfns-idebugfailureanalysis2) interface.

```cpp
FA_ENTRY entry = pAnalysis->Get(DEBUG_FLR_MANAGED_EXCEPTION_OBJECT);

while(NULL != entry)
{
   // Do something with the entry.

   entry = pAnalysis->GetNext(DEBUG_FLR_MANAGED_EXCEPTION_OBJECT, DEBUG_FLR_MASK_ALL);
}
```

**Example 2**

The following example shows how to find all FA entries that have tags in the Pool group. Recall the tags in the Pool group have values in the range 0x400, 0x401, ... 0x406. Assume `pAnalysis` is a pointer to an [IDebugFailureAnalysis2](https://learn.microsoft.com/windows-hardware/drivers/ddi/extsfns/nn-extsfns-idebugfailureanalysis2) interface.

```cpp
FA_ENTRY entry = pAnalysis->GetNext(NULL, (FA_TAG)0x400, (FA_TAG)0xFFFFFF00);

while(NULL != entry)
{
   // Do something with the entry.

   entry = pAnalysis->GetNext(entry, (FA_TAG)0x400, (FA_TAG)0xFFFFFF00);
}
```

**Example 3**

You can create your own custom tags in the range 0xA0000001 through 0xAFFFFFFF.

The following example shows how to find all failure analysis entries that have custom tags. In other words, the code finds all entries with tags that satisfy this condition:

`entry->Tag & 0xF0000000 == 0xA0000000`

Entries that have tags 0xA0000001, 0xA0000002, ... 0xAFFFFFF satisfy the condition.

```cpp

FA_ENTRY entry = pAnalysis->GetNext(NULL, (FA_TAG)0xA0000000, (FA_TAG)0xF0000000);

while(NULL != entry)
{
   // Do something with the Entry

   entry = pAnalysis->GetNext(entry, (FA_TAG)0xA0000000, (FA_TAG)0xF0000000);
}
```

## See also

[Get](https://learn.microsoft.com/windows-hardware/drivers/ddi/extsfns/nf-extsfns-idebugfailureanalysis-get)

[IDebugFailureAnalysis2](https://learn.microsoft.com/windows-hardware/drivers/ddi/extsfns/nn-extsfns-idebugfailureanalysis2)

[NextEntry](https://learn.microsoft.com/windows-hardware/drivers/ddi/extsfns/nf-extsfns-idebugfailureanalysis-nextentry)

[Writing an Analysis Extension Plug-in to Extend !analyze](https://learn.microsoft.com/windows-hardware/drivers/debugger/writing-an-analysis-extension-to-extend--analyze)

[_EFN_Analyze](https://learn.microsoft.com/windows-hardware/drivers/ddi/extsfns/nc-extsfns-ext_analysis_plugin)