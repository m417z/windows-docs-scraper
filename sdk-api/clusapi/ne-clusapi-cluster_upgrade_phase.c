typedef enum _CLUSTER_UPGRADE_PHASE {
  ClusterUpgradePhaseInitialize = 1,
  ClusterUpgradePhaseValidatingUpgrade = 2,
  ClusterUpgradePhaseUpgradingComponents = 3,
  ClusterUpgradePhaseInstallingNewComponents = 4,
  ClusterUpgradePhaseUpgradeComplete = 5
} CLUSTER_UPGRADE_PHASE;