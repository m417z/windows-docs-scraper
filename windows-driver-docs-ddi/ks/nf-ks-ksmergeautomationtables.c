KSDDKAPI NTSTATUS KsMergeAutomationTables(
  [out]          PKSAUTOMATION_TABLE *AutomationTableAB,
  [in, optional] PKSAUTOMATION_TABLE AutomationTableA,
  [in, optional] PKSAUTOMATION_TABLE AutomationTableB,
  [in, optional] KSOBJECT_BAG        Bag
);