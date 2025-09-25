# SHGLOBALCOUNTER enumeration

## Description

Identifiers for various global counters, or shared variables. Each global counter can be incremented or decremented using [SHGlobalCounterIncrement](https://learn.microsoft.com/windows/desktop/api/shlwapi/nf-shlwapi-shglobalcounterincrement) and [SHGlobalCounterDecrement](https://learn.microsoft.com/windows/desktop/api/shlwapi/nf-shlwapi-shglobalcounterdecrement).

## Constants

### `GLOBALCOUNTER_SEARCHMANAGER`

The global counter for use with the [ISearchManager](https://learn.microsoft.com/windows/desktop/api/searchapi/nn-searchapi-isearchmanager).

### `GLOBALCOUNTER_SEARCHOPTIONS`

The global counter for use with [ISearchQueryHelper](https://learn.microsoft.com/windows/desktop/api/searchapi/nn-searchapi-isearchqueryhelper) to identify whether a query parser's settings have changed.

### `GLOBALCOUNTER_FOLDERSETTINGSCHANGE`

The global counter used to identify whether folder settings have changed.

### `GLOBALCOUNTER_RATINGS`

The global counter used to identify whether ratings have changed.

### `GLOBALCOUNTER_APPROVEDSITES`

The global counter used to identify whether approved sites have changed.

### `GLOBALCOUNTER_RESTRICTIONS`

The global counter used to identify whether restrictions have changed.

### `GLOBALCOUNTER_SHELLSETTINGSCHANGED`

The global counter used to identify whether Shell settings have changed.

### `GLOBALCOUNTER_SYSTEMPIDLCHANGE`

The global counter used to identify whether a system PIDL has changed.

### `GLOBALCOUNTER_OVERLAYMANAGER`

The global counter used to identify whether the overlay manager state has changed.

### `GLOBALCOUNTER_QUERYASSOCIATIONS`

The global counter used to identify whether query associations have changed.

### `GLOBALCOUNTER_IESESSIONS`

The global counter used to identify whether the number of IE sessions has changed.

### `GLOBALCOUNTER_IEONLY_SESSIONS`

The global counter used to identify whether the number of IE sessions has changed.

### `GLOBALCOUNTER_APPLICATION_DESTINATIONS`

Identifies The global counter used to identify whether applications have been added or removed from the system.

### `__UNUSED_RECYCLE_WAS_GLOBALCOUNTER_CSCSYNCINPROGRESS`

Unused.

### `GLOBALCOUNTER_BITBUCKETNUMDELETERS`

The global counter used to identify deletions to the Recycle Bin.

### `GLOBALCOUNTER_RECYCLEDIRTYCOUNT_SHARES`

The global counter used to identify whether settings have changed on a share.

### `GLOBALCOUNTER_RECYCLEDIRTYCOUNT_DRIVE_A`

The global counter used to identify whether settings have changed on drive A.

### `GLOBALCOUNTER_RECYCLEDIRTYCOUNT_DRIVE_B`

The global counter used to identify whether settings have changed on drive B.

### `GLOBALCOUNTER_RECYCLEDIRTYCOUNT_DRIVE_C`

The global counter used to identify whether settings have changed on drive C.

### `GLOBALCOUNTER_RECYCLEDIRTYCOUNT_DRIVE_D`

The global counter used to identify whether settings have changed on drive D.

### `GLOBALCOUNTER_RECYCLEDIRTYCOUNT_DRIVE_E`

The global counter used to identify whether settings have changed on drive E.

### `GLOBALCOUNTER_RECYCLEDIRTYCOUNT_DRIVE_F`

The global counter used to identify whether settings have changed on drive F.

### `GLOBALCOUNTER_RECYCLEDIRTYCOUNT_DRIVE_G`

The global counter used to identify whether settings have changed on drive G.

### `GLOBALCOUNTER_RECYCLEDIRTYCOUNT_DRIVE_H`

The global counter used to identify whether settings have changed on drive H.

### `GLOBALCOUNTER_RECYCLEDIRTYCOUNT_DRIVE_I`

The global counter used to identify whether settings have changed on drive I.

### `GLOBALCOUNTER_RECYCLEDIRTYCOUNT_DRIVE_J`

The global counter used to identify whether settings have changed on drive J.

### `GLOBALCOUNTER_RECYCLEDIRTYCOUNT_DRIVE_K`

The global counter used to identify whether settings have changed on drive K.

### `GLOBALCOUNTER_RECYCLEDIRTYCOUNT_DRIVE_L`

The global counter used to identify whether settings have changed on drive L.

### `GLOBALCOUNTER_RECYCLEDIRTYCOUNT_DRIVE_M`

The global counter used to identify whether settings have changed on drive M.

### `GLOBALCOUNTER_RECYCLEDIRTYCOUNT_DRIVE_N`

The global counter used to identify whether settings have changed on drive N.

### `GLOBALCOUNTER_RECYCLEDIRTYCOUNT_DRIVE_O`

The global counter used to identify whether settings have changed on drive O.

### `GLOBALCOUNTER_RECYCLEDIRTYCOUNT_DRIVE_P`

The global counter used to identify whether settings have changed on drive P.

### `GLOBALCOUNTER_RECYCLEDIRTYCOUNT_DRIVE_Q`

The global counter used to identify whether settings have changed on drive Q.

### `GLOBALCOUNTER_RECYCLEDIRTYCOUNT_DRIVE_R`

The global counter used to identify whether settings have changed on drive R.

### `GLOBALCOUNTER_RECYCLEDIRTYCOUNT_DRIVE_S`

The global counter used to identify whether settings have changed on drive S.

### `GLOBALCOUNTER_RECYCLEDIRTYCOUNT_DRIVE_T`

The global counter used to identify whether settings have changed on drive T.

### `GLOBALCOUNTER_RECYCLEDIRTYCOUNT_DRIVE_U`

The global counter used to identify whether settings have changed on drive U.

### `GLOBALCOUNTER_RECYCLEDIRTYCOUNT_DRIVE_V`

The global counter used to identify whether settings have changed on drive V.

### `GLOBALCOUNTER_RECYCLEDIRTYCOUNT_DRIVE_W`

The global counter used to identify whether settings have changed on drive W.

### `GLOBALCOUNTER_RECYCLEDIRTYCOUNT_DRIVE_X`

The global counter used to identify whether settings have changed on drive X.

### `GLOBALCOUNTER_RECYCLEDIRTYCOUNT_DRIVE_Y`

The global counter used to identify whether settings have changed on drive Y.

### `GLOBALCOUNTER_RECYCLEDIRTYCOUNT_DRIVE_Z`

The global counter used to identify whether settings have changed on drive Z.

### `__UNUSED_RECYCLE_WAS_GLOBALCOUNTER_RECYCLEDIRTYCOUNT_SERVERDRIVE`

Unused.

### `__UNUSED_RECYCLE_WAS_GLOBALCOUNTER_RECYCLEGLOBALDIRTYCOUNT`

Unused.

### `GLOBALCOUNTER_RECYCLEBINENUM`

The global counter used to identify whether the Recycle Bin settings have changed.

### `GLOBALCOUNTER_RECYCLEBINCORRUPTED`

The global counter used to identify whether a Recycle Bin has been deleted.

### `GLOBALCOUNTER_RATINGS_STATECOUNTER`

The global counter used to identify whether ratings have changed.

### `GLOBALCOUNTER_PRIVATE_PROFILE_CACHE`

The global counter state.

### `GLOBALCOUNTER_INTERNETTOOLBAR_LAYOUT`

The global counter used to identify whether the Internet toolbar layout has changed.

### `GLOBALCOUNTER_FOLDERDEFINITION_CACHE`

The global counter used to identify changes to the folder definition cache.

### `GLOBALCOUNTER_COMMONPLACES_LIST_CACHE`

The global counter used to identify state changes for the commonplaces list cache.

### `GLOBALCOUNTER_PRIVATE_PROFILE_CACHE_MACHINEWIDE`

The global counter state, machine-wide.

### `GLOBALCOUNTER_ASSOCCHANGED`

The global counter used to identify the current GlobalAssocChangedCounter registry value for HKEY_LOCAL_MACHINE\Software\Microsoft\Windows\CurrentVersion\Explorer.

### `GLOBALCOUNTER_APP_ITEMS_STATE_STORE_CACHE`

**Introduced in Windows 8**. The global counter used to identify whether the Store is current.

### `GLOBALCOUNTER_SETTINGSYNC_ENABLED`

**Introduced in Windows 8**. The global counter used to determine whether sync is enabled or disabled.

### `GLOBALCOUNTER_APPSFOLDER_FILETYPEASSOCIATION_COUNTER`

**Introduced in Windows 8**. The global counter used to identify the current FTACounter registry value for HKEY_CURRENT_USER\Software\Microsoft\Windows\CurrentVersion\ImmersiveShell\StateStore.

### `GLOBALCOUNTER_USERINFOCHANGED`

**Introduced in Windows 8**. The global counter used to identify user info change state.

### `GLOBALCOUNTER_SYNC_ENGINE_INFORMATION_CACHE_MACHINEWIDE`

**Introduced in Windows 8.1**. The global counter used to identify sync engine counter state, machine wide..

### `GLOBALCOUNTER_BANNERS_DATAMODEL_CACHE_MACHINEWIDE`

### `GLOBALCOUNTER_MAXIMUMVALUE`

The maximum value any shared variable can have.

## Remarks

These global counters are shared variables that can help identify whether the state of a Windows component has changed over time. They can be used with these functions: [SHGlobalCounterDecrement](https://learn.microsoft.com/windows/desktop/api/shlwapi/nf-shlwapi-shglobalcounterdecrement), [SHGlobalCounterIncrement](https://learn.microsoft.com/windows/desktop/api/shlwapi/nf-shlwapi-shglobalcounterincrement), [SHGlobalCounterGetValue](https://learn.microsoft.com/windows/desktop/api/shlwapi/nf-shlwapi-shglobalcountergetvalue).

### Example

The following pseudocode example shows how a global counter can be used.

```
void ValidateSomeSettings()
    {
        // Get the current GLOBALCOUNTER_SHELLSETTINGSCHANGED value.
        long lGlobalSettingsCounter = SHGlobalCounterGetValue(GLOBALCOUNTER_SHELLSETTINGSCHANGED);

        // Do some other work
        ...

        // Verify whether the Shell settings have changed since entering this method.
        if (lGlobalSettingsCounter == SHGlobalCounterGetValue(GLOBALCOUNTER_SHELLSETTINGSCHANGED))
        {
            // Commit the work that was done earlier
            ...
        }

        else
        {
            // Shell settings have changed. Rollback and redo.
            ...
        }
    }
```

## See also

[SHGlobalCounterDecrement](https://learn.microsoft.com/windows/desktop/api/shlwapi/nf-shlwapi-shglobalcounterdecrement)

[SHGlobalCounterGetValue](https://learn.microsoft.com/windows/desktop/api/shlwapi/nf-shlwapi-shglobalcountergetvalue)

[SHGlobalCounterIncrement](https://learn.microsoft.com/windows/desktop/api/shlwapi/nf-shlwapi-shglobalcounterincrement)