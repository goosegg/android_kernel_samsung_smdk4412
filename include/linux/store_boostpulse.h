/*
 * Boostpulse support for ondemand based governors, based on Steve Kondik's solution for ondemand,
 * modified to work on multiple governors by Gustavo Santos, 2013.
 */

static ssize_t store_boosttime(struct kobject *kobj, struct attribute *attr,
				const char *buf, size_t count)
{
	unsigned int input;
	int ret;

	ret = sscanf(buf, "%u", &input);
	if (ret != 1)
		return -EINVAL;

	dbs_tuners_ins.freq_boost_time = input;
	return count;
}


static ssize_t store_boostpulse(struct kobject *kobj, struct attribute *attr,
				const char *buf, size_t count)
{
	int ret;
	unsigned long val;

	ret = kstrtoul(buf, 0, &val);
	if (ret < 0)
		return ret;

	dbs_tuners_ins.boosted = 1;
	freq_boosted_time = ktime_to_us(ktime_get());
	return count;
}

static ssize_t store_boostfreq(struct kobject *a, struct attribute *b,
				   const char *buf, size_t count)
{
	unsigned int input;
	int ret;
	ret = sscanf(buf, "%u", &input);
	if (ret != 1)
		return -EINVAL;
	dbs_tuners_ins.boostfreq = input;
	return count;
}
