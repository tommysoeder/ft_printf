

{
	void	*ptr;
	unsigned long	addr;
				
	ptr = va_arg(args, void *);
	addr = (unsigned long)ptr;
	write(1, "0x", 2);
	total += 2 + ft_puthex_ptr(addr);
}