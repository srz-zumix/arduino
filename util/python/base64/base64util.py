#! /usr/bin/env python
# -*- coding:utf-8 -*-

import base64
import sys

def main():
	if len(sys.argv) > 1:
		print base64.b64encode( sys.argv[1] )

if __name__ == '__main__':
	main()
