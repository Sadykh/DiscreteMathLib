#include "MegaNatural.h"
MegaNatural::MegaNatural()
{
	nums.push_back((uchar)0);
}
MegaNatural::MegaNatural(const MegaNatural &ob)
{	
	nums = deque<uchar>(ob.nums);
}
MegaNatural::MegaNatural(string str)
{
	bool isInputCorrect = true;
	for (int i = 0; i < str.length() && isInputCorrect; i++)
	{
		uchar c = (uchar)(str[i] - '0');
		if (c > 9)
		{
			std::cout << "Error! Incorrect string in MegaNatural constructor.";
			isInputCorrect = false;
		}
		else
			nums.push_front(c);
	}
}

MegaNatural::~MegaNatural()
{
}

ostream& operator<<(std::ostream &os,MegaNatural &ob)
{
	os << ob.toString();
	return os;
}

string MegaNatural::toString()
{
	string temp;
	for (int i = 0; i < nums.size(); i++)
		temp+=(char)(nums[nums.size()-1 - i] + '0');
	return temp;
}

//Описание: умножение на цифру
void MegaNatural::mulByK(long long k) {}

//Описание: умножение на 10^k
void MegaNatural::mulByTenPowK(long long k) 
{
	if (*this != 0)
		if (k < 0)
			while (k++ && *this != 0)
				if (nums.size() > 1)
					nums.pop_front();
				else
					nums[0] = 0;
		else 
			while (k--)
				nums.push_front(0);
}

long long MegaNatural::tenDivisiorCt()
{
	long long ct = 0;
	deque<uchar>::iterator it;
	for (it = nums.begin(); it < nums.end() && *it == 0; it++)
		ct++;
	return ct;
}

//Описание: вычитание натурального, умноженного на цифру
void MegaNatural::subNatMulK(const MegaNatural &ob, long long k) {
	MegaNatural a = ob;
	MegaNatural result = 0;

	a.mulByK(k);

	result = a - nums;
	if (result <= 0)
	{
		std::cout << "Error! Result is negative.";
	}
	else
	{
		nums = result;
	}
}

int MegaNatural::firstDigOfDivByNat(const MegaNatural &ob)
{
	int i = 0;
	MegaNatural a = ob;
	MegaNatural b = 0;
	while (*this >= a)
	{
		a.mulByTenPowK(1);
	}
	a.nums.pop_front();
	while (*this >= a)
	{
		i++;
		b = b + ob;
	}
	return i - 1;
}

bool operator ==(const MegaNatural &ob1, const MegaNatural &ob2)
{
	int len1 = ob1.nums.size(), len2 = ob2.nums.size();
	bool frbile = len1 > len2;
	if (len1 >= len2)
	{
		int i = 0;
		for (; i < len2; i++)
		if (ob1.nums.at(i) != ob2.nums.at(i))
			return 0;
		for (; i < len1; i++)
		if (ob1.nums.at(i) != 0)
			return 0;
	}
	else
	{
		int i=0;
		for (; i < len1; i++)
		if (ob1.nums.at(i) != ob2.nums.at(i))
			return 0;
		for (; i < len2; i++)
		if (ob2.nums.at(i) != 0)
			return 0;
	}

	return 1;



	return false;
}

bool operator !=(const MegaNatural &ob1, const MegaNatural &ob2)
{
	int len1 = ob1.nums.size(), len2 = ob2.nums.size();

	if (len1 >= len2)
	{
		int i = 0;
		for (; i < len2; i++)
		if (ob1.nums.at(i) != ob2.nums.at(i))
			return 1;
		for (; i < len1; i++)
		if (ob1.nums.at(i) != 0)
			return 1;
	}
	else
	{
		int i = 0;
		for (; i < len1; i++)
		if (ob1.nums.at(i) != ob2.nums.at(i))
			return 1;
		for (; i < len2; i++)
		if (ob2.nums.at(i) != 0)
			return 1;
	}

	return 0;



	return false;
}

bool operator <=(const MegaNatural &ob1, const MegaNatural &ob2)
{
	int len1 = ob1.nums.size(), len2 = ob2.nums.size();

	if (len1 >= len2)
	{
		int i = len1 - 1;
		for (; i >= len2; i--)
		if (ob1.nums.at(i) != 0)
			return 0;
		for (; i >= 0; i--)
		if (ob1.nums.at(i) != ob2.nums.at(i))
			return ob1.nums.at(i) < ob2.nums.at(i);
	}
	else
	{
		int i = len2 - 1;
		for (; i >= len1; i--)
		if (ob2.nums.at(i) != 0)
			return 1;
		for (; i >= 0; i--)
		if (ob1.nums.at(i) != ob2.nums.at(i))
			return ob1.nums.at(i) < ob2.nums.at(i);
	}

	return 1;
}

bool operator >=(const MegaNatural &ob1, const MegaNatural &ob2)
{
	int len2 = ob1.nums.size(), len1 = ob2.nums.size();

	if (len2 >= len1)
	{
		int i = len2 - 1;
		for (; i >= len1; i--)
		if (ob1.nums.at(i) != 0)
			return 0;
		for (; i >= 0; i--)
		if (ob2.nums.at(i) != ob1.nums.at(i))
			return ob2.nums.at(i) < ob1.nums.at(i);
	}
	else
	{
		int i = len1 - 1;
		for (; i >= len2; i--)
		if (ob1.nums.at(i) != 0)
			return 1;
		for (; i >= 0; i--)
		if (ob2.nums.at(i) != ob1.nums.at(i))
			return ob2.nums.at(i) < ob1.nums.at(i);
	}

	return 1;
}

bool operator <(const MegaNatural &ob1, const MegaNatural &ob2)
{
	int len2 = ob1.nums.size(), len1 = ob2.nums.size();

	if (len2 >= len1)
	{
		int i = len2 - 1;
		for (; i >= len1; i--)
		if (ob2.nums.at(i) != 0)
			return 1;
		for (; i >= 0; i--)
		if (ob2.nums.at(i) != ob1.nums.at(i))
			return ob2.nums.at(i) >= ob1.nums.at(i);
	}
	else
	{
		int i = len1 - 1;
		for (; i >= len2; i--)
		if (ob1.nums.at(i) != 0)
			return 0;
		for (; i >= 0; i--)
		if (ob2.nums.at(i) != ob1.nums.at(i))
			return ob2.nums.at(i) >= ob1.nums.at(i);
	}

	return 0;
}

bool operator >(const MegaNatural &ob1, const MegaNatural &ob2)
{
	int len1 = ob1.nums.size(), len2 = ob2.nums.size();

	if (len1 >= len2)
	{
		int i = len1 - 1;
		for (; i >= len2; i--)
		if (ob1.nums.at(i) != 0)
			return 1;
		for (; i >= 0; i--)
		if (ob1.nums.at(i) != ob2.nums.at(i))
			return ob1.nums.at(i) >= ob2.nums.at(i);
	}
	else
	{
		int i = len2 - 1;
		for (; i >= len1; i--)
		if (ob2.nums.at(i) != 0)
			return 0;
		for (; i >= 0; i--)
		if (ob1.nums.at(i) != ob2.nums.at(i))
			return ob1.nums.at(i) >= ob2.nums.at(i);
	}

	return 0;
}

MegaNatural& MegaNatural::operator =(const MegaNatural &ob)
{
   this->nums = deque<uchar>(ob.nums);
   return *this;
}

MegaNatural& MegaNatural::operator =(const long long a)
{
	MegaNatural ob;
	return ob;
}

MegaNatural operator +(const MegaNatural &ob1, const MegaNatural ob2)
{
   MegaNatural res;
   const MegaNatural* max_obj = (a.nums.size() >= b.nums.size()) ? &a : &b;
   const MegaNatural* min_obj = (a.nums.size() <= b.nums.size()) ? &a : &b;

   res = *max_obj;
   res.nums.push_back(0);

   for (int i = 0; i < min_obj->nums.size(); i++)
   {
	  res.nums[i] += min_obj->nums[i];
	  if (res.nums[i] >= 10)
	  {
		 res.nums[i] %= 10;
		 res.nums[i + 1] += 1;
	  }
   }

   for (int i = min_obj->nums.size(); res.nums[i] >= 10 && i < max_obj->nums.size(); i++)
   {
	  res.nums[i] %= 10;
	  res.nums[i + 1] += 1;
   }

   if (res.nums[res.nums.size() - 1] == 0)
	  res.nums.pop_back();

   return res;
}

MegaNatural operator -(const MegaNatural &ob1, const MegaNatural ob2)
{
	MegaNatural res, tmp;
	unsigned int i = 0, j = 0;
	res = ob1;
	tmp = ob2;
	deque<uchar>::iterator iter1 = res.nums.end();
	deque<uchar>::iterator iter;
	deque<uchar>::iterator iter2 = tmp.nums.end();
	if(res < ob2)
	{
		cout << "Resulting value isn't natural" << endl;
		return res;
	}
	if(res == ob2)
	{
		for(i = 1; i < res.nums.size(); i++)
		{
			res.nums.pop_back();
		}
		res.nums[0] = 0;
		return res;
	}
	if(ob1 > ob2)
	{
		for(i = 0; i < ob1.nums.size(); i++)
		{
			if(j > ob2.nums.size())
			{
				break;
			}
			if(*iter1 >= *iter2)
			{
				*iter1 = *iter1 - *iter2;
				iter1--;
				iter2--;
			}
			else if(*iter1 < *iter2)
			{
				*iter1 = (*iter1 + 10) - *iter2;
				*(iter1 - 1) = *(iter1 - 1) - 1;
				iter1--;
				iter2--;
			}
			j++;
		}
		iter = res.nums.begin();
		while(*iter == 0)
			{
				iter++;
				res.nums.pop_front();
			}
		return res;
	}
}

MegaNatural operator /(const MegaNatural &ob1, const MegaNatural ob2)
{
	MegaNatural res;
	if(ob1 < ob2)
	{
		return res;
	}
	deque<uchar>::iterator iter;
	res.nums.push_front(0);
	while(ob1 >= ob2)
	{
		ob1 = ob1 - ob2;
		for (iter = res.nums.end(); iter != res.nums.begin(); iter--)
		{
			if(*iter >= 0 && *iter < 9)
			{
				*iter = *iter + 1;
				break;
			}
			if(*iter == 9)
			{
				*iter = 0;
				if(*(iter - 1) == 9)
					{
						continue;
					}
				*(iter - 1) = *(iter - 1) + 1;
				if(*(iter - 1) == res.nums.begin())
				{
					res.nums.push_front(0);
				}

			}
		}
	}
	iter = res.nums.begin();
		while(*iter == 0)
			{
				iter++;
				res.nums.pop_front();
			}
	return res;
}

MegaNatural operator %(const MegaNatural &ob1, const MegaNatural ob2)
{
	MegaNatural ob;
	return ob;
}

MegaNatural operator *(const MegaNatural &ob1, const MegaNatural ob2)
{
	MegaNatural ob;
	return ob;
}