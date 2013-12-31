#include <linux/syscalls.h>

#define BOOSTPULSE_ONDEMAND "/sys/devices/system/cpu/cpufreq/ondemand/boostpulse"
#define BOOSTPULSE_PEGASUSQ "/sys/devices/system/cpu/cpufreq/pegasusq/boostpulse"
#define BOOSTPULSE_HYPER "/sys/devices/system/cpu/cpufreq/HYPER/boostpulse"

static struct boost_exynos4 {
  int boostpulse_fd;
} boost = {
  .boostpulse_fd = -1,
 };

static inline int boostpulse_open(void)
{
  if (boost.boostpulse_fd < 0)
  {
    boost.boostpulse_fd = sys_open(BOOSTPULSE_ONDEMAND, O_WRONLY, 0);
    if (boost.boostpulse_fd < 0)
    {boost.boostpulse_fd = sys_open(BOOSTPULSE_PEGASUSQ, O_WRONLY, 0);}
    if (boost.boostpulse_fd < 0)
    {boost.boostpulse_fd = sys_open(BOOSTPULSE_HYPER, O_WRONLY, 0);}
  }
 return boost.boostpulse_fd;
}

inline void touchboost_ondemand(void)
{
  int len;

  if (boostpulse_open() >= 0)
  {
    len = sys_write(boost.boostpulse_fd, "1", sizeof(BOOSTPULSE_ONDEMAND));
                        
    if (len < 0)
    {
      pr_info("Ondemand governor is not active, can't open %s\n", BOOSTPULSE_ONDEMAND);                        
    }
  }
}

inline void touchboost_pegasusq(void)
{
  int len;

  if (boostpulse_open() >= 0)
  {
    len = sys_write(boost.boostpulse_fd, "1", sizeof(BOOSTPULSE_PEGASUSQ));
                        
    if (len < 0)
    {
      pr_info("Pegasusq governor is not active, can't open %s\n", BOOSTPULSE_PEGASUSQ);                        
    }
  }
}

inline void touchboost_HYPER(void)
{
  int len;

  if (boostpulse_open() >= 0)
  {
    len = sys_write(boost.boostpulse_fd, "1", sizeof(BOOSTPULSE_HYPER));
                        
    if (len < 0)
    {
      pr_info("HYPER governor is not active, can't open %s\n", BOOSTPULSE_HYPER);                        
    }
  }
}
