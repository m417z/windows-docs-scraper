# PFNKSREMOVEEVENT callback function

## Description

An AVStream minidriver's *AVStrMiniRemoveEvent* routine is called when a client requests to be removed from the notification queue for an event. This routine is optional.

## Parameters

### `FileObject` [in]

Pointer to the file object for which to remove the event.

### `EventEntry` [in]

Pointer to an AVStream-generated [KSEVENT_ENTRY](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_ksevent_entry) structure.

## Remarks

The minidriver specifies this routine's address in the **RemoveHandler** member of a [KSEVENT_ITEM](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-ksevent_item) structure. [Event Handling in AVStream](https://learn.microsoft.com/windows-hardware/drivers/stream/event-handling-in-avstream) describes how the minidriver provides this structure to the class driver.

If the minidriver provides *AVStrMiniRemoveEvent* and either does not specify an **AddHandler** or specifies an **AddHandler** that calls **Ks***Xxx***AddEvent**, then the minidriver's *AVStrMiniRemoveEvent* must call [RemoveEntryList](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-removeentrylist) with a pointer to the LIST_ENTRY structure in the [KSEVENT_ENTRY](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_ksevent_entry) structure:

```cpp
&EventEntry -> ListEntry
```

Otherwise, your *AVStrMiniRemoveEvent* should reverse the steps taken in the **AddHandler**.

## See also

[AVStrMiniAddEvent](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nc-ks-pfnksaddevent)

[KSAUTOMATION_TABLE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-ksautomation_table_)

[KSEVENTDATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-kseventdata)

[KSEVENT_ENTRY](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_ksevent_entry)

[KSEVENT_ITEM](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-ksevent_item)

[KsFilterAddEvent](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksfilteraddevent)

[KsFilterGenerateEvents](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksfiltergenerateevents)

[KsPinAddEvent](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-kspinaddevent)

[KsPinGenerateEvents](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-kspingenerateevents)